#include "gtest-1.8.1/gtest.h"

#include "../src/trie_set.h"
#include "../src/Tipos.h"
#include "../src/Letra.h"
#include "../src/Tablero.h"
#include "../src/Variante.h"
#include "../src/Juego.h"

TEST(tests_interno_juego, crear_juego) {
    Variante v(5, 2, {1,2,3}, new trie_set());
    Repositorio mazo;
    for (int i = 0; i < 10; i++) {
        mazo.push_back(inversaDeOrd(i));
    }
    Juego(3, v, mazo);
}

TEST(tests_interno_juego, ubicar) {
    Variante v(5, 2, {1}, new trie_set());
    Repositorio mazo = {'c', 'a', 'z', 'z'};
    Juego j(1, v, mazo);

    Ocurrencia o = {tuple<Nat, Nat, Letra>(1, 1, 'c'), tuple<Nat, Nat, Letra>(1, 2, 'a')};

    j.ubicar(o);
    ASSERT_TRUE(j.hay_letra(1, 1));
    ASSERT_EQ(j.letra(1, 1), 'c');
    ASSERT_TRUE(j.hay_letra(1, 2));
    ASSERT_EQ(j.letra(1, 2), 'a');
}


TEST(tests_interno_juego, sumar_puntos_un_vertical) {
    vector<Nat> puntos_letra(TAMANIO_ALFABETO, 0);
    puntos_letra[ord('h')] = 10;
    puntos_letra[ord('o')] = 1;
    puntos_letra[ord('l')] = 2;
    puntos_letra[ord('a')] = 3;
    Nat hola_puntos = 16;
    Variante v(4, 4, puntos_letra, new trie_set());

    Repositorio mazo = {'h', 'o', 'l', 'a'};
    Juego j(1, v, mazo);

    Ocurrencia o = {
        tuple<Nat, Nat, Letra>(1, 0, 'h'), tuple<Nat, Nat, Letra>(1, 1, 'o'),
        tuple<Nat, Nat, Letra>(1, 2, 'l'), tuple<Nat, Nat, Letra>(1, 3, 'a')
    };

    ASSERT_EQ(j.puntaje(0), 0);
    j.ubicar(o);
    ASSERT_EQ(j.puntaje(0), hola_puntos << 1);
}

TEST(tests_interno_juego, sumar_puntos_un_horizontal) {
    vector<Nat> puntos_letra(TAMANIO_ALFABETO, 0);
    puntos_letra[ord('h')] = 10;
    puntos_letra[ord('o')] = 1;
    puntos_letra[ord('l')] = 2;
    puntos_letra[ord('a')] = 3;
    Nat hola_puntos = 16;
    Variante v(4, 4, puntos_letra, new trie_set());

    Repositorio mazo;
    mazo.push_back('h');
    mazo.push_back('o');
    mazo.push_back('l');
    mazo.push_back('a');
    Juego j(1, v, mazo);

    Ocurrencia o = {
        tuple<Nat, Nat, Letra>(0, 1, 'h'), tuple<Nat, Nat, Letra>(1, 1, 'o'),
        tuple<Nat, Nat, Letra>(2, 1, 'l'), tuple<Nat, Nat, Letra>(3, 1, 'a')
    };

    ASSERT_EQ(j.puntaje(0), 0);
    j.ubicar(o);
    ASSERT_EQ(j.puntaje(0), hola_puntos << 1);
}

TEST(tests_interno_juego, sumar_puntos_varios) {
    vector<Nat> puntos_letra(TAMANIO_ALFABETO, 0);
    puntos_letra[ord('h')] = 10;
    puntos_letra[ord('o')] = 1;
    puntos_letra[ord('l')] = 2;
    puntos_letra[ord('a')] = 3;
    puntos_letra[ord('s')] = 7;
    puntos_letra[ord('i')] = 22;
    puntos_letra[ord('c')] = 11;
    Variante v(5, 8, puntos_letra, new trie_set());

    Repositorio mazo;
    for (int i = 0; i < 8; i++) {
        mazo.push_back(inversaDeOrd(i % TAMANIO_ALFABETO));
    }
    Juego j(1, v, mazo);

    Nat hola_puntos = 10 + 1 + 2 + 3;
    Ocurrencia o_hola = {
        tuple<Nat, Nat, Letra>(1, 1, 'h'), tuple<Nat, Nat, Letra>(1, 2, 'o'),
        tuple<Nat, Nat, Letra>(1, 3, 'l'), tuple<Nat, Nat, Letra>(1, 4, 'a')
    };

    Nat si_puntos = 7 + 22;
    Ocurrencia o_si = {
        tuple<Nat, Nat, Letra>(3, 3, 's'), tuple<Nat, Nat, Letra>(3, 4, 'i')
    };

    Nat clas_puntos = 11 + 2 + 3 + 7;
    Ocurrencia o_clas = {
        tuple<Nat, Nat, Letra>(0, 3, 'c'), tuple<Nat, Nat, Letra>(2, 3, 'a')
    };

    j.ubicar(o_hola);
    j.ubicar(o_si);
    j.ubicar(o_clas);

    ASSERT_EQ(j.puntaje(0), 2 * hola_puntos + 2 * si_puntos + clas_puntos + 11 + 3);
}

TEST(tests_interno_juego, jugada_valida) {
    trie_set legitimas;
    legitimas.insert({'h', 'o', 'l', 'a'});
    legitimas.insert({'s', 'i'});
    legitimas.insert({'c', 'l', 'a', 's'});

    vector<Nat> puntos_letra(TAMANIO_ALFABETO, 0);
    puntos_letra[ord('h')] = 10;
    puntos_letra[ord('o')] = 1;
    puntos_letra[ord('l')] = 2;
    puntos_letra[ord('a')] = 3;
    puntos_letra[ord('s')] = 7;
    puntos_letra[ord('i')] = 22;
    puntos_letra[ord('c')] = 11;

    Variante v(5, TAMANIO_ALFABETO + 1, puntos_letra, new trie_set(legitimas));

    Repositorio mazo;
    for (int i = 0; i < TAMANIO_ALFABETO + 1; i++) {
        mazo.push_back(inversaDeOrd(i % TAMANIO_ALFABETO));
    }
    Juego j(1, v, mazo);

    Nat hola_puntos = 10 + 1 + 2 + 3;
    Ocurrencia o_hola = {
        tuple<Nat, Nat, Letra>(1, 1, 'h'), tuple<Nat, Nat, Letra>(1, 2, 'o'),
        tuple<Nat, Nat, Letra>(1, 3, 'l'), tuple<Nat, Nat, Letra>(1, 4, 'a')
    };

    Nat si_puntos = 7 + 22;
    Ocurrencia o_si = {
        tuple<Nat, Nat, Letra>(3, 3, 's'), tuple<Nat, Nat, Letra>(3, 4, 'i')
    };

    Nat clas_puntos = 11 + 2 + 3 + 7;
    Ocurrencia o_clas = {
        tuple<Nat, Nat, Letra>(0, 3, 'c'), tuple<Nat, Nat, Letra>(2, 3, 'a')
    };

    ASSERT_TRUE(j.jugada_valida(o_hola));
    j.ubicar(o_hola);

    ASSERT_TRUE(j.jugada_valida(o_si));
    j.ubicar(o_si);

    ASSERT_TRUE(j.jugada_valida(o_clas));
    j.ubicar(o_clas);

    ASSERT_EQ(j.puntaje(0), 2 * hola_puntos + 2 * si_puntos + clas_puntos + 11 + 3);
}

TEST(tests_interno_juego, jugada_invalida_palabra_ilegitima) {
    trie_set legitimas;
    vector<Nat> puntos_letra(TAMANIO_ALFABETO, 5);
    Variante v(5, 4, puntos_letra, new trie_set(legitimas));

    Repositorio mazo = {'h', 'o', 'l', 'a'};
    Juego j(1, v, mazo);

    Ocurrencia o_hola = {
        make_tuple(1, 1, 'h'), make_tuple(1, 2, 'o'),
        make_tuple(1, 3, 'l'), make_tuple(1, 4, 'a')
    };
    ASSERT_FALSE(j.jugada_valida(o_hola));
}

TEST(tests_interno_juego, jugada_invalida_faltan_letras) {
    trie_set legitimas;
    legitimas.insert({'h', 'o', 'l', 'a'});
    vector<Nat> puntos_letra(TAMANIO_ALFABETO, 5);
    Variante v(5, 4, puntos_letra, new trie_set(legitimas));

    Repositorio mazo(TAMANIO_ALFABETO, 'h');
    Juego j(1, v, mazo);

    Ocurrencia o_hola = {
        make_tuple(1, 1, 'h'), make_tuple(1, 2, 'o'),
        make_tuple(1, 3, 'l'), make_tuple(1, 4, 'a')
    };
    ASSERT_FALSE(j.jugada_valida(o_hola));
}

TEST(tests_interno_juego, jugada_invalida_falta_cantidad_mano) {
    trie_set legitimas;
    legitimas.insert({'h', 'o', 'l', 'a'});
    vector<Nat> puntos_letra(TAMANIO_ALFABETO, 5);
    Variante v(5, 3, puntos_letra, new trie_set(legitimas));

    Repositorio mazo = {'h', 'o', 'l', 'a'};
    Juego j(1, v, mazo);

    Ocurrencia o_hola = {
        make_tuple(1, 1, 'h'), make_tuple(1, 2, 'o'),
        make_tuple(1, 3, 'l'), make_tuple(1, 4, 'a')
    };
    ASSERT_FALSE(j.jugada_valida(o_hola));
}
