//
// Created by matias on 22/05/23.
//

#include "tests.h"
#include <gtest/gtest.h>
#include <vector>
#include "Sorting_Searching.h"
using namespace std;
////////////////////    Bubble Sort TESTS   //////////////////////
TEST(BubbleSortTest, ListaVacia) {
    vector<int> A;
    BubbleSort(A);
    EXPECT_TRUE(A.empty());
}

TEST(BubbleSortTest, ListaConUnElemento) {
    vector<int> A = {5};
    BubbleSort(A);
    EXPECT_EQ(A, vector<int>({5}));
}

TEST(BubbleSortTest, ListaOrdenada) {
    vector<int> A = {1, 2, 3, 4, 5};
    BubbleSort(A);
    EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(BubbleSortTest, ListaEnOrdenDescendente) {
    vector<int> A = {5, 4, 3, 2, 1};
    BubbleSort(A);
    EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(BubbleSortTest, ListaDesordenada) {
    vector<int> A = {3, 1, 4, 2, 5};
    BubbleSort(A);
    EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(BubbleSortTest, ListaConElementosRepetidos) {
    vector<int> A = {3, 1, 4, 2, 5, 4, 2};
    BubbleSort(A);
    EXPECT_EQ(A, vector<int>({1, 2, 2, 3, 4, 4, 5}));
}
    ////////////////////    Insertion Sort TESTS   //////////////////////

TEST(InsertionSortTest, ListaConUnElemento) {
vector<int> A = {5};
InsertionSort(A);
EXPECT_EQ(A, vector<int>({5}));
}

TEST(InsertionSortTest, ListaOrdenada) {
vector<int> A = {1, 2, 3, 4, 5};
InsertionSort(A);
EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(InsertionSortTest, ListaEnOrdenDescendente) {
vector<int> A = {5, 4, 3, 2, 1};
InsertionSort(A);
EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(InsertionSortTest, ListaDesordenada) {
vector<int> A = {3, 1, 4, 2, 5};
InsertionSort(A);
EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(InsertionSortTest, ListaConElementosRepetidos) {
vector<int> A = {3, 1, 4, 2, 5, 4, 2};
InsertionSort(A);
EXPECT_EQ(A, vector<int>({1, 2, 2, 3, 4, 4, 5}));
}

////////////////////    Selection Sort TESTS   //////////////////////
TEST(SelectionSortTest, ListaVacia) {
    vector<int> A;
    SelectionSort(A);
    EXPECT_TRUE(A.empty());
}

TEST(SelectionSortTest, ListaConUnElemento) {
    vector<int> A = {5};
    SelectionSort(A);
    EXPECT_EQ(A, vector<int>({5}));
}

TEST(SelectionSortTest, ListaOrdenada) {
    vector<int> A = {1, 2, 3, 4, 5};
    SelectionSort(A);
    EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(SelectionSortTest, ListaEnOrdenDescendente) {
    vector<int> A = {5, 4, 3, 2, 1};
    SelectionSort(A);
    EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(SelectionSortTest, ListaDesordenada) {
    vector<int> A = {3, 1, 4, 2, 5};
    SelectionSort(A);
    EXPECT_EQ(A, vector<int>({1, 2, 3, 4, 5}));
}

TEST(SelectionSortTest, ListaConElementosRepetidos) {
    vector<int> A = {3, 1, 4, 2, 5, 4, 2};
    SelectionSort(A);
    EXPECT_EQ(A, vector<int>({1, 2, 2, 3, 4, 4, 5}));
}


////////////////////    Binary Search TESTS   //////////////////////
TEST(BusquedaBinariaTest, ElementoPresente) {
vector<int> A = {1, 2, 5, 8, 9};
EXPECT_TRUE(BusquedaBinaria(A, 1));
EXPECT_TRUE(BusquedaBinaria(A, 8));
EXPECT_TRUE(BusquedaBinaria(A, 2));

vector<int> B = {1,6,8,33,787,3242,12333,342425,234235567};
EXPECT_TRUE(BusquedaBinaria(B,342425));
EXPECT_TRUE(BusquedaBinaria(B,3242));
}

TEST(BusquedaBinariaTest, ElementoNoPresente) {
vector<int> A = {1, 2, 5, 8, 9};
EXPECT_FALSE(BusquedaBinaria(A, 4));
EXPECT_FALSE(BusquedaBinaria(A, 0));
EXPECT_FALSE(BusquedaBinaria(A, 12));

vector<int> B = {1,6,8,33,787,3242,12333,342425,234235567};
EXPECT_FALSE(BusquedaBinaria(B,342435));
EXPECT_FALSE(BusquedaBinaria(B,242));
}
////////////////////    Lineal Search TESTS   //////////////////////
TEST(BusquedaLinealTest, ElementoPresente) {
vector<int> A = {1, 2, 5, 8, 9};
EXPECT_TRUE(BusquedaLineal(A, 5));
EXPECT_TRUE(BusquedaLineal(A, 2));
EXPECT_TRUE(BusquedaLineal(A, 9));

vector<int> B = {3,5,1,1,5,0,2,4,3,2,3,4321,4,325,234,2};
EXPECT_TRUE(BusquedaLineal(B, 4321));
EXPECT_TRUE(BusquedaLineal(B, 2));
EXPECT_TRUE(BusquedaLineal(B, 234));
}

TEST(BusquedaLinealTest, ElementoNoPresente) {
    vector<int> A = {1, 2, 5, 8, 9};
    EXPECT_FALSE(BusquedaLineal(A, 32));
    EXPECT_FALSE(BusquedaLineal(A, 0));
    EXPECT_FALSE(BusquedaLineal(A, 11));

    vector<int> B = {3,5,1,1,5,0,2,4,3,2,3,4321,4,325,234,2};
    EXPECT_FALSE(BusquedaLineal(A, 4322));
    EXPECT_FALSE(BusquedaLineal(A, 232));
    EXPECT_FALSE(BusquedaLineal(A, 6));
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}