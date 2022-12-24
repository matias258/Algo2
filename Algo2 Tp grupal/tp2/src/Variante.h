#ifndef GUGEL_VARIANTE_H
#define GUGEL_VARIANTE_H

#include "Tipos.h"
#include "Letra.h"
#include "trie_set.h"

class Variante {

public:
    Variante();
    Variante(const Variante& v);
    Variante(Nat tam_tablero, Nat cant_fichas, vector<Nat>, trie_set*);
    ~Variante();
    Nat puntaje_letra(Letra) const;
    Nat tam_tablero() const;
    Nat cantidad_fichas() const;
    bool es_legitima(vector<Letra>) const;
    unsigned l_max();
    Variante& operator=(const Variante&);
private:
    Nat _tam_tablero;
    Nat _cantidad_fichas;
    vector<Nat> letras_puntaje;
    trie_set* palabras_legitimas;
};

#endif
