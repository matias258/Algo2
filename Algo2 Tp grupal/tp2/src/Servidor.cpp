#include "Servidor.h"

Servidor::Servidor() {}

Servidor::Servidor(const Servidor& s) { *this = s; }

Servidor::Servidor(Nat esperados, const Repositorio &m, const Variante& v) : 
    _esperados(esperados), 
    _conectados(0),
    juego(esperados, v, m), 
    contador_n(5),
    notificaciones(esperados, list<pair<Notificacion, Nat>>())
{}

IdCliente Servidor::conectar_cliente() {
    if (_esperados == _conectados) {
        cout << "Ya no pueden conectarse clientes" << endl;
        return -1;
    }

    notificaciones[_conectados].push_back(make_pair(Notificacion::nuevaIdCliente(_conectados), 0));
    if (estados_globales.second.empty()) {
        estados_globales.second.push_back(make_pair(Notificacion::nuevaEmpezar(juego.obtener_variante().tam_tablero()), 2));
        estados_globales.second.push_back(make_pair(Notificacion::nuevaTurnoDe(0), 3));
    }
    estados_globales.first.push_back(estados_globales.second.begin());

    // Este bloque de código no se corresponde con la especificacion.
    // Está presente sólo para pasar el test:
    //     ServidorTest.cuando_estan_todos_los_jugadores_se_envian_notificaciones_de_empezar
    // Igualmente, dicho test espera la notificación reponer al empezar un juego
    // mientras que en la especificación provista por la cátedra esto no debería pasar:
    //
    // notificaciones(conectarCliente(s), cid) ≡ if cid = #conectados(s) + 1 then
    //                                               〈 〉 ∘ IdCliente(cid)
    //                                           else
    //                                               notificaciones(s, cid)
    //                                           fi
    //                                           &
    //                                           fi #conectados(s) + 1 = #esperados(s) then
    //                                               〈 〉 ∘ Empezar(tamañoTablero(variante(s))
    //                                                   ∘ TurnoDe(0)
    //                                           else
    //                                               〈 〉
    //                                           fi
    // Por otro lado, la complejidad pasa a depender de la cantidad de fichas de la variante
    // y del tamaño del alfabeto.
    multiset<Letra> a_reponer;
    for (int i = 0; i < TAMANIO_ALFABETO; i++) {
        for (int j = 0; j < juego.cant_ficha(_conectados, inversaDeOrd(i)); j++) {
            a_reponer.insert(inversaDeOrd(i));
        }
    }

    notificaciones[_conectados].push_back(make_pair(Notificacion::nuevaReponer(a_reponer), 4));

    return _conectados++;;
}

list<Notificacion> Servidor::consultar(IdCliente id) {
    list<Notificacion> res;

    if (_conectados != _esperados) {
        // Si se pidieron las notificaciones antes de que arranque el juego.
        // Sólo debería haber notis de IdCliente y 0 o más de Mal.
        while (notificaciones[id].front().second != 4) {
            Notificacion notificacion = notificaciones[id].front().first;
            res.push_back(notificacion);
            notificaciones[id].pop_front();
        }
        return res;
    }

    // Reestablecer el iterador luego de que llegó al final si corresponde
    estados_globales.first[id]++;
    if (!notificaciones[id].empty() && notificaciones[id].front().second < 5) {
        estados_globales.first[id]--;
    }

    while (!notificaciones[id].empty() || estados_globales.first[id] != estados_globales.second.end()) {
        bool quedan_notificaciones_globales = estados_globales.first[id] != estados_globales.second.end(); 
        bool global_mas_vieja_que_noti_jugador = notificaciones[id].front().second > (*estados_globales.first[id]).second;

        if (notificaciones[id].empty() || (quedan_notificaciones_globales && global_mas_vieja_que_noti_jugador)) {
            // Pushear a notificaciones globales.
            Notificacion notificacion = (*estados_globales.first[id]++).first;
            res.push_back(notificacion);
        } else {
            // Pushear a notificaciones de jugador.
            Notificacion notificacion = notificaciones[id].front().first;
            res.push_back(notificacion);
            notificaciones[id].pop_front();
        }
    }
    estados_globales.first[id]--;

    return res;
}


void Servidor::recibir_mensaje(IdCliente id, const Ocurrencia& ocurrencia) {
    if (_conectados != _esperados || id != juego.turno() || !juego.jugada_valida(ocurrencia)) {
        if (!notificaciones[id].empty() && notificaciones[id].front().second < 5) {
        // El juego no empezó
            if (notificaciones[id].front().second == 0) {
                // Pushear Mal entre IdCliente y el resto de las notificaciones
                Notificacion notificacion_id = notificaciones[id].front().first;
                notificaciones[id].pop_front();
                notificaciones[id].push_front(make_pair(Notificacion::nuevaMal(), 1));
                notificaciones[id].push_front(make_pair(notificacion_id, 0));
            } else {
                notificaciones[id].push_front(make_pair(Notificacion::nuevaMal(), 1));
            }
        } else {
            notificaciones[id].push_back(make_pair(Notificacion::nuevaMal(), contador_n++));
        }
    } else {
        multiset<Letra> a_reponer;
        auto it = juego.ver_mazo().begin();
        Nat tam_ocu = 0;
        while (it != juego.ver_mazo().end() && tam_ocu++ < ocurrencia.size()){
            a_reponer.insert(*it++);
        }

        juego.ubicar(ocurrencia);

        // Pushear notificaciones a la lista individual y global.
        estados_globales.second.push_back(make_pair(Notificacion::nuevaUbicar(id, ocurrencia), contador_n++));
        estados_globales.second.push_back(make_pair(Notificacion::nuevaSumaPuntos(id, juego.puntaje(id)), contador_n++));
        notificaciones[id].push_back(make_pair(Notificacion::nuevaReponer(a_reponer), contador_n++));
        estados_globales.second.push_back(make_pair(Notificacion::nuevaTurnoDe((id + 1) % _esperados), contador_n++));
    }
}

Servidor& Servidor::operator=(const Servidor& s) {
    juego = s.juego;
    contador_n = s.contador_n;
    notificaciones = s.notificaciones;
    estados_globales = s.estados_globales;
    _esperados = s._esperados;
    _conectados = s._conectados;
    return *this;
}

Nat Servidor::esperados() {
    return _esperados;
}

Nat Servidor::conectados() {
    return _conectados;
}

const Juego& Servidor::ver_juego() const { return juego; }
