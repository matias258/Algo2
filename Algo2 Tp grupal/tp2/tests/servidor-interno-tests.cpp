#include "gtest-1.8.1/gtest.h"
#include "../src/Servidor.h"

TEST(servidor_interno_tests, crear_servidor) {
    trie_set legitimas;
    Variante v(5, 5, {}, new trie_set(legitimas));
    Repositorio mazo;
    for (int i = 0; i < 15; i++) {
        mazo.push_back(inversaDeOrd(i));
    }
    Servidor s(3, mazo, v);
}
