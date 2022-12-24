#include "gtest-1.8.1/gtest.h"

#include "../src/Tipos.h"
#include "../src/Letra.h"
#include "../src/Tablero.h"

TEST(tests_interno_tablero, crear_tablero) {
    Tablero t(3);
}

TEST(tests_interno_tablero, agregar_letra){
    Tablero t(4);
    EXPECT_FALSE(t.hay_letra(0, 1));
    t.ubicar(0, 1, 'c', 8);

    EXPECT_TRUE(t.hay_letra(0, 1));
    EXPECT_EQ(t.tableroIJ(0, 1), 'c');
    EXPECT_EQ(t.acceder(0, 1), 8);
}

TEST(tests_interno_tablero, quitar_letra) {
    Tablero t(4);
    EXPECT_FALSE(t.hay_letra(0, 1));
    t.ubicar(0, 1, 'c', 8);

    EXPECT_TRUE(t.hay_letra(0, 1));
    EXPECT_EQ(t.tableroIJ(0, 1), 'c');
    EXPECT_EQ(t.acceder(0, 1), 8);

    t.desubicar(0, 1);
    EXPECT_FALSE(t.hay_letra(0,1));
}
