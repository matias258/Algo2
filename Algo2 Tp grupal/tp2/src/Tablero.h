#ifndef GUGEL_TABLERO_H
#define GUGEL_TABLERO_H

#include "Tipos.h"

class Tablero {
public:
    Tablero();
    Tablero(Nat n);
    Nat acceder(Nat i, Nat j ); // funcion [][] -ver si podemos hacerlo así-
    Letra tableroIJ(Nat i, Nat j);  // es la que esta en el tp1
    bool hay_letra(Nat i, Nat j);
    void ubicar(Nat, Nat, Letra, Nat);
    void desubicar(Nat, Nat);

private:

    Nat _tam;

    struct Casillero {
        int jugada;
        Letra letra;
        Casillero(Letra l, int j) : letra(l), jugada(j) { }
    };

    vector<vector<Casillero>> casilleros;
};
#endif //GUGEL_TABLERO_H

