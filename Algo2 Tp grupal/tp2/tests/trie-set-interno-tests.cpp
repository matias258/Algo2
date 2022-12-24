#include "gtest-1.8.1/gtest.h"
#include "../src/trie_set.h"
#include "utils/PalabrasComunes.h"

TEST(tests_interno_trie_set, palabras_legitimas) {
    trie_set* s = new trie_set;
    for (auto it: palabrasComunes) {
        s->insert(it);
    }
    delete s;
}

TEST(tests_interno_trie_set, vacio) {
    trie_set vacio;

    EXPECT_FALSE(vacio.defined({'h', 'o', 'l', 'a'}));
    EXPECT_EQ(vacio.max_length(), 0);
}

TEST(tests_interno_trie_set, asignar) {
    trie_set singleton;
    singleton.insert({'h', 'o', 'l', 'a'});

    EXPECT_TRUE(singleton.defined({'h', 'o', 'l', 'a'}));
    EXPECT_EQ(singleton.max_length(), 4);
}

TEST(tests_interno_trie_set, defined) {
    trie_set sin_prefijos;
    trie_set con_prefijos;

    sin_prefijos.insert({'h', 'o', 'l', 'a'});
    EXPECT_EQ(sin_prefijos.max_length(), 4);
    sin_prefijos.insert({'c', 'h', 'a', 'u'});
    EXPECT_EQ(sin_prefijos.max_length(), 4);
    sin_prefijos.insert({'a', 'd', 'i', 'o', 's'});
    EXPECT_EQ(sin_prefijos.max_length(), 5);

    con_prefijos.insert({'c'});
    EXPECT_EQ(con_prefijos.max_length(), 1);
    con_prefijos.insert({'c', 'a', 's', 'a'});
    EXPECT_EQ(con_prefijos.max_length(), 4);
    con_prefijos.insert({'c', 'a', 's', 'o', 'n', 'a'});
    EXPECT_EQ(con_prefijos.max_length(), 6);

    EXPECT_TRUE(sin_prefijos.defined({'h', 'o', 'l', 'a'}));
    EXPECT_TRUE(sin_prefijos.defined({'c', 'h', 'a', 'u'}));
    EXPECT_TRUE(sin_prefijos.defined({'a', 'd', 'i', 'o', 's'}));

    EXPECT_FALSE(sin_prefijos.defined({'h', 'o', 'l'}));
    EXPECT_FALSE(sin_prefijos.defined({'h', 'o'}));
    EXPECT_FALSE(sin_prefijos.defined({'h'}));

    EXPECT_TRUE(con_prefijos.defined({'c'}));
    EXPECT_TRUE(con_prefijos.defined({'c', 'a', 's', 'a'}));
    EXPECT_TRUE(con_prefijos.defined({'c', 'a', 's', 'o', 'n', 'a'}));
}

TEST(tests_interno_trie_set, copiar) {
    trie_set sin_prefijos;
    
    sin_prefijos.insert({'h', 'o', 'l', 'a'});
    sin_prefijos.insert({'c', 'h', 'a', 'u'});
    sin_prefijos.insert({'a', 'd', 'i', 'o', 's'});

    trie_set copia(sin_prefijos);
    EXPECT_EQ(copia.max_length(), 5);

    EXPECT_TRUE(copia.defined({'h', 'o', 'l', 'a'}));
    EXPECT_TRUE(copia.defined({'c', 'h', 'a', 'u'}));
    EXPECT_TRUE(copia.defined({'a', 'd', 'i', 'o', 's'}));

    copia.insert({'s', 'a', 'l', 'u', 'd', 'o'});
    EXPECT_EQ(copia.max_length(), 6);
    EXPECT_TRUE(copia.defined({'s', 'a', 'l', 'u', 'd', 'o'}));
    EXPECT_FALSE(sin_prefijos.defined({'s', 'a', 'l', 'u', 'd', 'o'}));
    EXPECT_EQ(sin_prefijos.max_length(), 5);
}
