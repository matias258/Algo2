#include "Fachada_Juego.h"

Fachada_Juego::Fachada_Juego(Nat k, const Fachada_Variante& v, const Repositorio& r) : fachada_variante(v) {
    Fachada_Variante fachada_variante = v;
    Juego j(k, fachada_variante.variante_interna(), r);
    juego = j;
}

void Fachada_Juego::ubicar(const Ocurrencia& o) { juego.ubicar(o); }

IdCliente Fachada_Juego::turno() { return juego.turno(); }

const Fachada_Variante& Fachada_Juego::variante() { return fachada_variante; }

bool Fachada_Juego::jugadaValida(const Ocurrencia& o) { return juego.jugada_valida(o); }

bool Fachada_Juego::hayLetra(Nat x, Nat y) { return juego.hay_letra(x, y); }

Letra Fachada_Juego::letra(Nat i, Nat j) { return juego.letra(i, j); }

Nat Fachada_Juego::puntaje(IdCliente id) { return juego.puntaje(id); }

Nat Fachada_Juego::cantFicha(IdCliente id, Letra l) { return juego.cant_ficha(id, l); }

const Juego& Fachada_Juego::juego_interno() { return juego; }
