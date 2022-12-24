/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iterator>
#include <utility>
using namespace std;


int main()
{
    int array[9]{6, 4, 7, 3, 2, 2, 1, 9, 5};
    
    for (int i=0; i < size(array) - 1; i++){
        
        int menor = array[i];
        int indMen = i;
        for (int j = i + 1; j < size(array); j++){
            if (array[j] <= menor){
                menor = array[j];
                indMen = j;
            }
        }
        swap(array[i], array[indMen]);
    }
    
    for (int k = 0; k < size(array); k++){
        cout << array[k] << " ";
    }
    return 0;
}




