#include "gtest-1.8.1/gtest.h"

#include "../src/Tipos.h"
#include "../src/Letra.h"
#include "../src/Jugador.h"

TEST(jugador_interno_test, agregar_quitar_letra){
    Jugador j; 

    j.agregar_letra_mano('c');
    j.agregar_letra_mano('c');
    j.agregar_letra_mano('a');
    j.agregar_letra_mano('z');

    ASSERT_EQ(j.cant_fichas_por_letra('c'), 2);
    j.sacar_letra_mano('c');
    ASSERT_EQ(j.cant_fichas_por_letra('c'), 1);

    ASSERT_EQ(j.cant_fichas_por_letra('a'), 1);
    ASSERT_EQ(j.cant_fichas_por_letra('z'), 1);
}

TEST(jugador_interno_tests, agregar_quitar_jugada) {
    Jugador j; 

    j.agregar_jugada(Ocurrencia({tuple<Nat, Nat, Letra>(2, 2, 'h')}), 2);
    j.agregar_jugada(Ocurrencia({tuple<Nat, Nat, Letra>(3, 2, 'o'), tuple<Nat, Nat, Letra>(4, 2, 'x')}), 3);
    
    pair<Ocurrencia, Nat> esperada = pair<Ocurrencia, Nat>({tuple<Nat, Nat, Letra>(2, 2, 'h')}, 2);
    ASSERT_TRUE(j.mostrar_jugada() == esperada);

    j.quitar_jugada();
    esperada = pair<Ocurrencia, Nat>({tuple<Nat, Nat, Letra>(3, 2, 'o'), tuple<Nat, Nat, Letra>(4, 2, 'x')}, 3);
    ASSERT_TRUE(j.mostrar_jugada() == esperada);
}
/*
void agregar_letra_mano (Jugador &j, Letra l);

void sacar_letra_mano (Jugador &j, Letra l);


void sumar_puntos (Jugador &j, Nat n);


void agregar_jugada (Jugador &j, Ocurrencia o, Nat p);

tuple<Ocurrencia, Nat> mostrar_jugada (Jugador &j);


void quitar_jugada (Jugador &j);

bool historial_vacio (Jugador &j);

PuntosTotales puntos_totales (Jugador j);

Nat cant_fichas_por_letra (Jugador j, Letra l);


TEST(jugador_interno_tests, mano) {
    crear_mano(); // debe devolver un vector lleno de 0 de longitud 10
}

TEST(jugador_interno_test, puntosTotales){
    TAMANIO_ALFABETO = 20;
    crear_mano();
    puntos_totales();
}
*/
