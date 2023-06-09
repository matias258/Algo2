//
// Created by matias on 22/05/23.
//

#include "tests.h"
#include <gtest/gtest.h>
#include <vector>
#include "Sorting_Searching.h"
using namespace std;

////////////////////    Counting Sort TESTS   //////////////////////
TEST(CountingSortTest, CorrectSorting) {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    std::vector<int> expected = {1, 2, 2, 3, 3, 4, 8};
    ASSERT_EQ(CountingSort(arr), expected);
}

// Prueba unitaria para verificar la ordenación de un arreglo vacío
TEST(CountingSortTest, EmptyArray) {
    vector<int> arr;
    vector<int> expected;
    ASSERT_EQ(CountingSort(arr), expected);
}

// Prueba unitaria para verificar la ordenación de un arreglo ya ordenado
TEST(CountingSortTest, AlreadySortedArray) {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> expected = {1, 2, 3, 4, 5};
    ASSERT_EQ(CountingSort(arr), expected);
}

// Prueba unitaria para verificar la ordenación de un arreglo en orden descendente
TEST(CountingSortTest, DescendingOrderArray) {
    vector<int> arr = {9, 7, 5, 3, 1};
    vector<int> expected = {1, 3, 5, 7, 9};
    ASSERT_EQ(CountingSort(arr), expected);
}

TEST(CountingSortTest, ArrayWithDuplicates) {
    vector<int> arr = {3, 2, 1, 2, 1, 3};
    vector<int> expected = {1, 1, 2, 2, 3, 3};
    ASSERT_EQ(CountingSort(arr), expected);
}


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
////////////////////////    Insertion Sort TESTS   //////////////////////

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

///////////////////// Max Heap TESTS ///////////////////////////////
TEST(HeapSortTest, CorrectSorting) {
    std::vector<int> arr = {4, 2, 9, 6, 1, 3, 8, 5, 7};
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    HeapSort(arr);

    ASSERT_EQ(arr, expected);
}

TEST(HeapSortTest, EmptyArray) {
    std::vector<int> arr;
    std::vector<int> expected;

    HeapSort(arr);

    ASSERT_EQ(arr, expected);
}


TEST(HeapSortTest, AlreadySortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    HeapSort(arr);

    // Verificar si el arreglo ya ordenado se mantiene igual
    ASSERT_EQ(arr, expected);
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


////////////////////    MERGE SORT TESTS   //////////////////////
TEST(MergeSortTest, EmptyVector) {
    std::vector<int> input;
    std::vector<int> expected;

    // Ordenar el vector de entrada utilizando MergeSort
    std::vector<int> result = MergeSort(input);

    // Verificar que el resultado es igual al vector esperado
    EXPECT_EQ(result, expected);
}

// Prueba para un vector con un solo elemento
TEST(MergeSortTest, SingleElementVector) {
    std::vector<int> input = {5};
    std::vector<int> expected = {5};

    // Ordenar el vector de entrada utilizando MergeSort
    std::vector<int> result = MergeSort(input);

    // Verificar que el resultado es igual al vector esperado
    EXPECT_EQ(result, expected);
}

// Prueba para un vector con varios elementos desordenados
TEST(MergeSortTest, UnsortedVector) {
    std::vector<int> input = {7, 3, 5, 1, 9};
    std::vector<int> expected = {1, 3, 5, 7, 9};

    // Ordenar el vector de entrada utilizando MergeSort
    std::vector<int> result = MergeSort(input);

    // Verificar que el resultado es igual al vector esperado
    EXPECT_EQ(result, expected);
}

// Prueba para un vector que ya está ordenado
TEST(MergeSortTest, SortedVector) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};

    // Ordenar el vector de entrada utilizando MergeSort
    std::vector<int> result = MergeSort(input);

    // Verificar que el resultado es igual al vector esperado
    EXPECT_EQ(result, expected);
}

// Prueba para un vector con elementos duplicados
TEST(MergeSortTest, VectorWithDuplicates) {
    std::vector<int> input = {4, 2, 1, 4, 3, 2};
    std::vector<int> expected = {1, 2, 2, 3, 4, 4};

    // Ordenar el vector de entrada utilizando MergeSort
    std::vector<int> result = MergeSort(input);

    // Verificar que el resultado es igual al vector esperado
    EXPECT_EQ(result, expected);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}