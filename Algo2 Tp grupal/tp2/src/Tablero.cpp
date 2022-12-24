#include "Tablero.h"

Tablero::Tablero() : _tam(0) {}

Tablero::Tablero(Nat n) {
    for(int i=0; i < n; i++){
        vector<Casillero> aux;
        for(int j=0; j<n; j++){
            aux.push_back(Casillero(' ', -1));
        }
        casilleros.push_back(aux);
    }
    _tam = n;
}

Letra Tablero::tableroIJ(Nat i, Nat j) {
    return casilleros[i][j].letra;
}

Nat Tablero::acceder(Nat i, Nat j) {
    return casilleros[i][j].jugada;
}

bool Tablero::hay_letra(Nat i, Nat j) {
    return casilleros[i][j].letra != ' ';
}

void Tablero::ubicar(Nat i, Nat j, Letra l, Nat t) {
    casilleros[i][j].letra = l;
    casilleros[i][j].jugada = t;
}

void Tablero::desubicar(Nat i, Nat j) {
    casilleros[i][j].letra = ' ';
    casilleros[i][j].jugada = -1;
}
