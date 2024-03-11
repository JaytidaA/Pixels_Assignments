/*
    Name: Aaditya J.
    Pixels Ass1_Q3
*/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::swap;
using std::size_t;

void sort(int *, size_t);

int main()
{
    int * array_Elem;
    size_t size_Arr;
    cout << "Please enter the size: "; cin >> size_Arr;     //😜🤤
    array_Elem = new int[size_Arr];

    cout << "Please enter the elements of the array: ";
    for(int i = 0; i < size_Arr; i++){
        cin >> *(array_Elem + i);
    }

    cout << endl;
    sort(array_Elem, size_Arr);

    for(int i = 0; i < size_Arr; i++)
    {
        cout << *(array_Elem + i) << "\t";
    }

    delete [] array_Elem;
    return 0;
}

void sort(int * array_Sort, size_t size_Arr){
    for(int i = 0; i < size_Arr - 1; i++){
        //Start of Pass
        for(int j = 0; j < size_Arr - i - 1; j++){
            if(array_Sort[j] > array_Sort[j + 1]){
                swap(array_Sort[j], array_Sort[j + 1]);
                //If elements are in descending order, swap them.
            }
        }//End of Pass
    }
}