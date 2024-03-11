/*
    Name: Aaditya J.
    Pixels Ass1_Q1
*/
#include <iostream>
#include "functions.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    double * input_Arr1D, ** input_Arr2D;
    input_Arr1D = new double[9];
    input_Arr2D = new double*[3];
    for(int i = 0; i < 3; i++){
        input_Arr2D[i] = new double[4];
    }

    cout << "Enter elements of 2D Array: \n";
    array_enter(input_Arr2D, 3, 4);

    cout << "Enter elements of 1D Array: \n";
    array_enter(input_Arr1D, 9);

    array_display(input_Arr1D, 9);
    array_display(input_Arr2D, 3, 4);

    delete [] input_Arr1D;
    delete [] input_Arr2D;
    //Deallocating memory

    return 0;
}