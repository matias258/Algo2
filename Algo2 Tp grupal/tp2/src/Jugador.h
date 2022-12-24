#ifndef GUGEL_JUGADORES_H
#define GUGEL_JUGADORES_H

#include "Tipos.h"
#include "Letra.h"

class Jugador {
public:

    Jugador();

    void agregar_letra_mano(Letra l);

    void sacar_letra_mano(Letra l);

    void sumar_puntos(Nat n);

    void agregar_jugada(Ocurrencia o, Nat p);

    pair<Ocurrencia, Nat> mostrar_jugada();

    void quitar_jugada();

    bool historial_vacio();

    Nat puntos_totales();

    Nat cant_fichas_por_letra(Letra l);

private:
    Nat puntos;
    Nat mano[TAMANIO_ALFABETO] = {0};
    JugadasPasadas historial;
};

#endif //GUGEL_JUGADORES_H
