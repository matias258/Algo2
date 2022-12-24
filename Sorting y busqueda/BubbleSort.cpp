/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iterator> // for std::size
#include <utility>

using namespace std;

int main()
{
    int array[]{ 6, 2, 2, 9, 7, 1, 5, 4, 8 };

    constexpr int length{ std::size(array) };
    for (int i=0; i < length-1; i++)
    {

        for (int j= 0; j < length - 1; j++)
        {
        
            if (array[j] > array[j+1])
                swap(array[j], array[j + 1]);
        }
    }

    for (int k=0 ; k < length; k++){
        cout << array[k] << ' ';
    }

    return 0;
}



