/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iterator>

using namespace std;


int main()
{
    constexpr int array[9]{6, 4, 7, 3, 8, 2, 1, 9, 5};
    
    int n;
    cout << "Elegi un numero del 1 al 9: " <<endl;
    cin >> n;
    while (n < 1 || n > 9){
        
        cout << "Elegi un numero del 1 al 9: " <<endl;
        cin >> n;
        
    }
    cout << "El array completo es: "<<endl;
    //printeamos el array
    for (int i = 0; i < size(array); i++){
        if (i == size(array) - 1){
            cout << array[i] <<endl;
        }
        else{
            cout << array[i] << " ";
        }
        
    }
    
    int max = array[0];
    int indiceMax = 0;
    //buscamos el indice de n
    
    for (int j = 0; j < size(array); j++){
        if (array[j] == n){
            cout <<"El numero: " <<n<< " tiene indice " << j <<endl;
        }
        if (max < array[j]){
            max = array[j];
            indiceMax = j;
        }
    }
    cout << "El maximo valor es: " <<max << " y esta ubicado en el indice: " <<indiceMax<<endl;

    return 0;
}





