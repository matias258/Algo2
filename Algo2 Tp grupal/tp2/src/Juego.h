#ifndef GUGEL_JUEGO_H
#define GUGEL_JUEGO_H

#include "Tipos.h"
#include "Letra.h"
#include "Variante.h"
#include "Tablero.h"
#include "Jugador.h"
#include <queue>

class Juego {
public: 
    Juego();
    Juego(const Juego&);
    Juego(Nat esperados, const Variante& v, const Repositorio m);
    bool jugada_valida(const Ocurrencia&);
    void ubicar(const Ocurrencia&);
    IdCliente turno(); 
    Nat puntaje(IdCliente);
    Nat cant_ficha(IdCliente, Letra);
    const Variante& obtener_variante();
    bool hay_letra(Nat, Nat);
    Letra letra(Nat, Nat);
    Juego& operator=(const Juego&);
    const Repositorio& ver_mazo();
private:
    Variante variante;
    Tablero tablero;
    Repositorio mazo_fichas;
    Nat _turno;
    Nat cantidad_jugadores;
    vector<Jugador> jugadores;

    void ubicar_sin_concecuencia(Ocurrencia);
    bool es_horizontal(Ocurrencia);
    bool es_vertical(Ocurrencia);
    void desubicar(Ocurrencia);
};

#endif
