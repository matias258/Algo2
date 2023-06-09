//
// Created by matias on 21/05/23.
//
#include "vector"
using namespace std;

#ifndef ALGORITMOS_DS_SORTING_H
#define ALGORITMOS_DS_SORTING_H

//Auxiliares
int Min(vector<int> A);
int Max(vector<int> A);
void Swap(int& x, int& y);

//Bubble Sort
void BubbleSort(vector<int>& A);

//Insertion Sort
void InsertionSort(vector<int>& (A));

//Selection Sort
void SelectionSort(vector<int>& (A));

//Counting Sort
vector<int> CountingSort(vector<int>&(A));

//Merge Sort
vector<int> MergeSort(vector<int>& (A));

//Heap Sort
void MaxHeapify(vector<int>&(A), int i, int size);
void HeapSort(vector<int>&(A));

//Busqueda binaria
vector<int> SubVect(vector<int> A, int start, int end);
bool BusquedaBinaria(vector<int> A, int x);

//Busqueda lineal
bool BusquedaLineal(vector<int> A, int x);

#endif //ALGORITMOS_DS_SORTING_H
