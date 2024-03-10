/*
    Name: Aaditya J.
    Pixels Ass1_Q1
*/
#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void array_enter(double * arr_1d, int size_Arr){
    cout << "Enter " << size_Arr << " elements.\n";
    for(int i = 0; i < size_Arr; i++){
        cin >> *(arr_1d + i);
    }
    cout << endl;
}


void array_enter(double ** arr_2d, int dim1, int dim2){
    cout << "Enter " << dim1 * dim2 << " elements.\n";
    for(int i = 0; i < dim1; i++){
        for(int j = 0; j < dim2; j++){
            cin >> *(*(arr_2d + i) + j);
            /*
                Get the address of pointer arr_2d[i],
                add j to it to get to the desired element,
                and use the indirection operator to access that element.
            */
        }
    }
    cout << endl;
}

void array_display(double * arr_1d, int size_Arr){
    cout << "Elements of 1D Array at Index which is a multiple of 3:\n";
    for(int i = 0; i < size_Arr; i = i + 3){
        cout << *(arr_1d + i) << "\t"; 
    }
    cout << endl << endl;
}

void array_display(double ** arr_2d, int dim1, int dim2){
    cout << "Elements of 2D Array at Index which is a multiple of 3:\n";
    for(int i = 0; i < dim1; i++){
        for(int j = 0; j < dim2; j = j + 3){
            cout << *(*(arr_2d + i) + j) << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

#endif //FUNCTIONS_HPP