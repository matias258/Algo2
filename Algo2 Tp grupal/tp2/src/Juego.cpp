#include "Juego.h"

Juego::Juego() {}

Juego::Juego(const Juego& j) {
    *this = j;
}

Juego::Juego(Nat esperados, const Variante &v, const Repositorio m) {
    variante = v;
    tablero = Tablero(v.tam_tablero());
    _turno = 0;
    mazo_fichas = m;
    cantidad_jugadores = esperados;

    for (int i = 0; i < esperados; i++) {
        Jugador jugador;

        for (int j = 0; j < variante.cantidad_fichas(); j++) {
            if (!mazo_fichas.empty()) {
                jugador.agregar_letra_mano(mazo_fichas.front());
                mazo_fichas.pop_front();
            }
        }

        jugadores.push_back(jugador);
    }
}

void Juego::ubicar(const Ocurrencia &ocurrencia) {
    for (auto it: ocurrencia) {
        tablero.ubicar(get<0>(it), get<1>(it), get<2>(it), _turno);
        jugadores[turno()].sacar_letra_mano(get<2>(it));
        if (!mazo_fichas.empty()) {
            jugadores[turno()].agregar_letra_mano(mazo_fichas.front());
            mazo_fichas.pop_front();
        }
    }
    jugadores[turno()].agregar_jugada(ocurrencia, _turno);
    _turno++;
}

void Juego::ubicar_sin_concecuencia(Ocurrencia ocurrencia) {
    for (auto it: ocurrencia) {
        tablero.ubicar(get<0>(it), get<1>(it), get<2>(it), _turno);
    }
}

void Juego::desubicar(Ocurrencia ocurrencia) {
    for (auto it: ocurrencia) {
        tablero.ubicar(get<0>(it), get<1>(it), ' ', -1);
    }
}

IdCliente Juego::turno() {
    return cantidad_jugadores != 0 ? _turno % cantidad_jugadores : 0;
}

bool Juego::hay_letra(Nat i, Nat j) {
    // La precondición de que i, j tienen que estar en el rango del tablero,
    // nos permite aprovechar el caso indefinido para uso interno.
    // Esto sólo se usa para evaluar precondicion y devolver la post a la
    // vez. Hace falta chequear la pre porque nada impide previamente que un
    // jugador envie una ocurrencia que se encuentra fuera del tablero.
    if (i < variante.tam_tablero() && j < variante.tam_tablero()) {
        return tablero.hay_letra(i, j);
    } else {
        return false;
    }
}

Letra Juego::letra(Nat i, Nat j) {
    return tablero.tableroIJ(i, j);
}

bool Juego::es_vertical(Ocurrencia ocurrencia) {
    Nat pos_i = get<0>(*ocurrencia.begin());
    for (auto it: ocurrencia) {
        if (get<0>(it) != pos_i) {
            return false;
        }
    }
    return true;
}

bool Juego::es_horizontal(Ocurrencia ocurrencia) {
    Nat pos_j = get<1>(*ocurrencia.begin());
    for (auto it: ocurrencia) {
        if (get<1>(it) != pos_j) {
            return false;
        }
    }
    return true;
}

bool Juego::jugada_valida(const Ocurrencia& ocurrencia) {
    if (ocurrencia.empty()) {
        return true;
    }

    if (ocurrencia.size() > variante.l_max()) {
        return false;
    }

    multiset<Letra> fichas_necesarias;
    for (auto it: ocurrencia) {
        if (tablero.hay_letra(get<0>(it), get<1>(it))) {
            return false;
        }
        fichas_necesarias.insert(get<2>(it));
    }

    for (auto it: ocurrencia) {
        if (cant_ficha(turno(), get<2>(it)) < fichas_necesarias.count(get<2>(it))) {
           return false; 
        }
    }

    if (!es_horizontal(ocurrencia) && !es_vertical(ocurrencia)) {
        return false;
    }
    
    ubicar_sin_concecuencia(ocurrencia);
    Ocurrencia jugada_completa;
    vector<Letra> palabra_formada;

    if (es_vertical(ocurrencia)) {
        Nat columna = get<0>(*ocurrencia.begin());
        Nat filas = get<1>(*ocurrencia.begin());

        while (hay_letra(columna, filas - 1)) 
        { filas--; }
        
        while (hay_letra(columna, filas)) {
            jugada_completa.insert(tuple<Nat, Nat, Letra>(columna, filas, letra(columna, filas)));
            palabra_formada.push_back(letra(columna, filas));
            filas++;
        }

        for (auto it: ocurrencia) {
            if (jugada_completa.count(it) == 0) {
                desubicar(ocurrencia);
                return false;
            }
        }

        if (!variante.es_legitima(palabra_formada)) {
            desubicar(ocurrencia);
            return false;
        }

        for (auto it: ocurrencia) {
            palabra_formada.clear();
            Nat columnas = get<0>(it);
            Nat fila = get<1>(it);

            if (hay_letra(columnas - 1, fila) || hay_letra(columnas + 1, fila)) {
                while (hay_letra(columnas - 1, fila)) 
                { columnas--; }
                
                while (hay_letra(columnas, fila)) {
                    palabra_formada.push_back(letra(columnas, fila));
                    columnas++;
                }

                if (!variante.es_legitima(palabra_formada)) {
                    desubicar(ocurrencia);
                    return false;
                }
            }
        }
    } else {
        Nat columnas = get<0>(*ocurrencia.begin());
        Nat fila = get<1>(*ocurrencia.begin());

        while (hay_letra(columnas - 1, fila)) 
        { columnas--; }
        
        while (hay_letra(columnas, fila)) {
            jugada_completa.insert(tuple<Nat, Nat, Letra>(columnas, fila, letra(columnas, fila)));
            palabra_formada.push_back(letra(columnas, fila));
            columnas++;
        }

        for (auto it: ocurrencia) {
            if (jugada_completa.count(it) == 0) {
                desubicar(ocurrencia);
                return false;
            }
        }

        if (!variante.es_legitima(palabra_formada)) {
            desubicar(ocurrencia);
            return false;
        }

        for (auto it: ocurrencia) {
            palabra_formada.clear();
            Nat columna = get<0>(it);
            Nat filas = get<1>(it);

            if (hay_letra(columna, filas - 1) || hay_letra(columna, filas + 1)) {
                while (hay_letra(columna, filas - 1)) 
                { filas--; }
                
                while (hay_letra(columna, filas)) {
                    palabra_formada.push_back(letra(columna, filas));
                    filas++;
                }

                if (!variante.es_legitima(palabra_formada)) {
                    desubicar(ocurrencia);
                    return false;
                }
            }
        }
    }

    desubicar(ocurrencia);
    return true; 
}

Nat Juego::puntaje(IdCliente id) {
    if (jugadores[id].historial_vacio()) {
        return jugadores[id].puntos_totales();
    }

    Nat acc_puntos = 0;
    Ocurrencia ocurrencia = jugadores[id].mostrar_jugada().first;
    Nat turno_oc = jugadores[id].mostrar_jugada().second;

    if (es_vertical(ocurrencia)) {
        Nat columna = get<0>(*ocurrencia.begin());
        Nat filas = get<1>(*ocurrencia.begin());

        while (hay_letra(columna, filas - 1) && tablero.acceder(columna, filas - 1) <= turno_oc) 
        { filas--; }
        
        while (hay_letra(columna, filas) && tablero.acceder(columna, filas) <= turno_oc) {
            acc_puntos += variante.puntaje_letra(letra(columna, filas));
            filas++;
        }

        for (auto it: ocurrencia) {
            Nat columnas = get<0>(it);
            Nat fila = get<1>(it);
            while (hay_letra(columnas - 1, fila) && tablero.acceder(columnas - 1, fila) <= turno_oc) 
            { columnas--; }
            
            while (hay_letra(columnas, fila) && tablero.acceder(columnas, fila) <= turno_oc) {
                acc_puntos += variante.puntaje_letra(letra(columnas, fila));
                columnas++;
            }
        }
    } else {
        Nat columnas = get<0>(*ocurrencia.begin());
        Nat fila = get<1>(*ocurrencia.begin());

        while (hay_letra(columnas - 1, fila) && tablero.acceder(columnas - 1, fila) <= turno_oc) 
        { columnas--; }
        
        while (hay_letra(columnas, fila) && tablero.acceder(columnas, fila) <= turno_oc) {
            acc_puntos += variante.puntaje_letra(letra(columnas, fila));
            columnas++;
        }

        for (auto it: ocurrencia) {
            Nat columna = get<0>(it);
            Nat filas = get<1>(it);

            while (hay_letra(columna, filas - 1) && tablero.acceder(columna, filas - 1) <= turno_oc) 
            { filas--; }
            
            while (hay_letra(columna, filas) && tablero.acceder(columna, filas) <= turno_oc) {
                acc_puntos += variante.puntaje_letra(letra(columna, filas));
                filas++;
            }
        }
    }

    jugadores[id].quitar_jugada();
    jugadores[id].sumar_puntos(acc_puntos);
    return puntaje(id);
}

Nat Juego::cant_ficha(IdCliente id, Letra l) {
    return jugadores[id].cant_fichas_por_letra(l);
}

const Variante& Juego::obtener_variante() {
    return variante;
}

Juego& Juego::operator=(const Juego& j) {
    variante = j.variante;
    tablero = j.tablero;
    mazo_fichas = j.mazo_fichas;
    _turno = 0;
    cantidad_jugadores = j.cantidad_jugadores;
    jugadores = j.jugadores;
    return *this;
}

const Repositorio& Juego::ver_mazo() {
    return mazo_fichas;
}
