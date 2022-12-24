#include "Tipos.h"
#include "Jugador.h"
#include "Letra.h"

Jugador::Jugador() : puntos(0) {}
// La mano del jugador es un vector con longitud igual a TAMANIO_ALFABETO
void Jugador::agregar_letra_mano(Letra l){
    mano[ord(l)]++;
}

void Jugador::sacar_letra_mano(Letra l){
    mano[ord(l)]--;
}

void Jugador::sumar_puntos(Nat n){
    puntos += n;
}

void Jugador::agregar_jugada(Ocurrencia o, Nat p){
    pair<Ocurrencia, Nat> nueva_jugada = pair<Ocurrencia, Nat>(o, p);
    historial.push(nueva_jugada);
}

pair<Ocurrencia, Nat> Jugador::mostrar_jugada(){
    return historial.front();
}

void Jugador::quitar_jugada(){
    historial.pop();
}

bool Jugador::historial_vacio(){
    return historial.empty();
}

Nat Jugador::puntos_totales() {
    return puntos; // acceeder a la posicion 0 de la tupla jugadores
}

Nat Jugador::cant_fichas_por_letra(Letra l){
    Nat i = ord(l);
    return mano[i];
}
