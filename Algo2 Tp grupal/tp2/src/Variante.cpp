#include "Variante.h"

Variante::Variante(Nat tam_tablero, Nat cantidad_fichas, vector<Nat> letras_puntaje, trie_set* legitimas) : _tam_tablero(tam_tablero), _cantidad_fichas(cantidad_fichas), letras_puntaje(letras_puntaje), palabras_legitimas(legitimas) {}

Variante::Variante() : _tam_tablero(0), _cantidad_fichas(0), palabras_legitimas(NULL) {}

Variante::Variante(const Variante& v) {
    *this = v;
}

Variante::~Variante() {
    delete palabras_legitimas;
}

Nat Variante::tam_tablero() const {
    return _tam_tablero;
}

Nat Variante::cantidad_fichas() const {
    return _cantidad_fichas;
}

Nat Variante::puntaje_letra(Letra l) const {
    return letras_puntaje[ord(l)];
}

bool Variante::es_legitima(vector<Letra> p) const {
    return palabras_legitimas->defined(p);
}

unsigned Variante::l_max() {
    return palabras_legitimas->max_length();
}

Variante& Variante::operator=(const Variante& v) {
    _tam_tablero = v._tam_tablero;
    _cantidad_fichas = v._cantidad_fichas;
    letras_puntaje = v.letras_puntaje;
    palabras_legitimas = new trie_set(*v.palabras_legitimas);
    return *this;
}
