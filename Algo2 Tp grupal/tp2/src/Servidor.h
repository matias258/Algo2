#ifndef GUGEL_SERVIDOR_H
#define GUGEL_SERVIDOR_H

#include "Tipos.h"
#include "Notificacion.h"
#include "Juego.h"

class Servidor {
public:
    Servidor();
    Servidor(const Servidor&);
    Servidor(Nat esperados, const Repositorio&, const Variante&);
    IdCliente conectar_cliente();
    list<Notificacion> consultar(IdCliente);
    void recibir_mensaje(IdCliente, const Ocurrencia&);
    Nat esperados();
    Nat conectados();
    const Juego& ver_juego() const;
    Servidor& operator=(const Servidor&);
private:
    Juego juego;
    Nat contador_n;
    vector< list< pair<Notificacion, Nat> > > notificaciones;
    pair<
        vector< list<pair<Notificacion, Nat>>::iterator>,
        list< pair<Notificacion, Nat> >
    > estados_globales;
    Nat _esperados;
    Nat _conectados;
};

#endif
