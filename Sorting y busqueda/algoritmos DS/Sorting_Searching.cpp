//
// Created by matias on 21/05/23.
//

#include "Sorting_Searching.h"
#include <iostream>
#include <vector>
#include "climits"
using namespace std;

/////////////////////////////   AUXILIARES     ////////////////////////////////////////////////////////
void Swap(int& x, int& y) {
    int aux = x;
    x = y;
    y = aux;
}

int Max(vector<int> A) {
    int maximo = INT_MIN;
    for (int i = 0; i < A.size(); i++){
        if (maximo < A[i]) {
            maximo = A[i];
        }
    }
    return maximo;
}

int Min(vector<int> A) {
    int minimo = INT_MAX;
    for (int i = 0; i < A.size(); i++){
        if (minimo > A[i]) {
            minimo = A[i];
        }
    }
    return minimo;
}

//TODO faltan merge sort y quick sort



/////////////////////////////   BUBBLE SORT   O(n2)  ////////////////////////////////////////////////////////
void BubbleSort(vector<int>& A) {
    int size = A.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (A[i] > A[j]) {
                Swap(A[i], A[j]);
            }
        }
    }
}
/////////////////////////////   INSERTION SORT   O(n2) ////////////////////////////////////////////////////////
//Premisa: no puede estar vacia
void InsertionSort(vector<int>& (A)){
    for (int i = 0; i < A.size()-1; i++){
        for (int j = i+1; j < A.size(); j++){
            if (A[i] > A[j]){
                Swap(A[i], A[j]);
            }
        }
    }
}

/////////////////////////////   SELECTION SORT   O(n2) ////////////////////////////////////////////////////////
void SelectionSort(vector<int>& (A)){
    int min = INT_MAX;
    int indice = 0;

    for (int i = 0; i < A.size(); i++){
        for (int j = i; j < A.size(); j++){
            if (min > A[j]){
                min = A[j];
                indice = j;
            }
        }
        Swap(A[indice], A[i]);
        min = INT_MAX;
    }
}

/////////////////////////////   COUNTING SORT O(n+k)   ////////////////////////////////////////////////////////
vector<int> CountingSort(vector<int>&(A)){
    vector<int> Rango;
    vector<int> res;
    int min = Min(A);
    int max = Max(A);
    for (int i = min; i <= max; i++){
        Rango.push_back(0);
    }

    for (int j = 0; j < A.size(); j++){
        Rango[A[j] - min ] ++;
    }

    for (int k = 0; k < Rango.size(); k++){
        if (Rango[k] != 0){
            for (int l = 0; l < Rango[k]; l++){
                res.push_back(k + min);
            }
        }
    }
    return res;
}

/////////////////////////////   HEAP SORT O(n+k)   ////////////////////////////////////////////////////////
// Función para ajustar un subárbol en un Max-Heap dado un nodo raíz
void MaxHeapify(vector<int>& A, int i, int size) {
    int j = i;
    while (2 * j + 1 < size) {  // Mientras el nodo actual tenga al menos un hijo izquierdo
        int k = 2 * j + 1;      // Índice del hijo izquierdo
        if (2 * j + 2 < size && A[2 * j + 2] > A[k]) {  // Si hay un hijo derecho y es mayor que el hijo izquierdo
            k = 2 * j + 2;      // Actualizamos el índice al hijo derecho
        }
        if (A[j] < A[k]) {              // Si el valor del nodo actual es menor que el valor del hijo mayor
            swap(A[j], A[k]);     // Intercambiamos los valores
            j = k;                      // Actualizamos el índice al hijo mayor
        } else {                        // Si no se cumple la condición, el subárbol ya está en forma de Max-Heap
            break;
        }
    }
}

// Función para ordenar un vector utilizando HeapSort
void HeapSort(vector<int>& A) {
    int size = A.size();

    // Construir un Max-Heap a partir del vector original
    for (int i = size / 2 - 1; i >= 0; i--) {
        MaxHeapify(A, i, size);
    }

    // Extraer elementos del Max-Heap uno por uno y colocarlos al final del vector
    for (int i = size - 1; i > 0; i--) {
        swap(A[0], A[i]);
        MaxHeapify(A, 0, i);
    }
}

/////////////////////////////   BUSQUEDA LINEAL O(n)  ////////////////////////////////////////////////////////
bool BusquedaLineal(vector<int> A, int x){
    for (int i = 0; i < A.size(); i++){
        if (A[i] == x){
            return true;
        }
    }
    return false;
}

/////////////////////////////   BUSQUEDA BINARIA O(log(n))  ////////////////////////////////////////////////////////
vector<int> SubVect(vector<int> A, int start,int end){
    vector<int> res;
    if (end >= A.size()){
        end = A.size() - 1;
    }
    for (int i = start; i <= end; i++){
        res.push_back(A[i]);
    }
    return res;
}

//Premisa: El vector tiene que estar ordenado.
bool BusquedaBinaria(vector<int> A, int x){
    int p = A[A.size() / 2];
    int start = 0;
    int end = A.size()-1;

    if (A[0] == x){
        return true;
    }

    if ((A.size() <= 2 && A[0] != x && A[1] != x)){
        return false;
    }
    else if (p > x){
        end = A.size() / 2;
        return BusquedaBinaria(SubVect(A, start, end), x);
    }
    else if(p < x){
        start = A.size() / 2;
        return BusquedaBinaria(SubVect(A, start, end), x);
    }
    return true;
}