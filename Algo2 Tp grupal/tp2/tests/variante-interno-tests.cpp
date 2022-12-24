#include "gtest-1.8.1/gtest.h"

#include "../src/Tipos.h"
#include "../src/Letra.h"
#include "../src/Variante.h"
#include "../src/trie_set.h"

TEST(tests_interno_variante, crear_variante) {
    trie_set* legitimas = new trie_set;
    legitimas->insert({'h', 'o', 'l', 'a'});

    vector<Nat> puntajes_letra;
    for (int i = 0; i < TAMANIO_ALFABETO; i++) {
        puntajes_letra.push_back(i);
    }

    Variante v(5, 5, puntajes_letra, legitimas);
}

TEST(tests_interno_variante, obtener_puntaje) {
    trie_set legitimas;
    legitimas.insert({'h', 'o', 'l', 'a'});

    vector<Nat> puntajes_letra;
    for (int i = 0; i < TAMANIO_ALFABETO; i++) {
        puntajes_letra.push_back(i);
    }

    Variante v(5, 5, puntajes_letra, new trie_set(legitimas));

    ASSERT_EQ(v.puntaje_letra('b'), 1);
}

TEST(tests_interno_variante, palabras_legitimas) {
    trie_set legitimas;
    legitimas.insert({'h', 'o', 'l', 'a'});
    legitimas.insert({'o', 'l', 'a'});

    vector<Nat> puntajes_letra;
    for (int i = 0; i < TAMANIO_ALFABETO; i++) {
        puntajes_letra.push_back(i);
    }

    Variante v(5, 5, puntajes_letra, new trie_set(legitimas));

    EXPECT_TRUE(v.es_legitima({'h', 'o', 'l', 'a'}));
    EXPECT_TRUE(v.es_legitima({'o', 'l', 'a'}));
    EXPECT_FALSE(v.es_legitima({'a', 'l', 'o'}));
}
