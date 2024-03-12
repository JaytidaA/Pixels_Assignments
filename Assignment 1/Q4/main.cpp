/*
    Name: Aaditya J.
    Pixels Ass1_Q4
*/
#include <iostream>
#include <vector>
#include <climits>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::size_t;

int main()
{
    size_t size_Input;
    cout << "Enter the size of the vector: "; cin >> size_Input;
    vector<int> vec_Input(size_Input);
    vector<int>::iterator vec_In_Iter = vec_Input.begin();

    cout << "Input:\n";
    cout << "Enter " << size_Input << " elements:\n";
    while(vec_In_Iter != vec_Input.end()){
        cin >> *vec_In_Iter;
        vec_In_Iter++;
    }
    cout << endl;

    vec_In_Iter = vec_Input.begin();
    int MAX = INT_MIN, MIN = INT_MAX;
    /*
        Using the constants in climits to ensure that the output of MAX and MIN is correct
        Otherwise edge-cases exist like if minimum entry is a positive number then output of MIN will be 0
        Similar thing will happen if the maximum entry is a negative number.
    */
    while(vec_In_Iter != vec_Input.end()){
        MAX = (MAX < *vec_In_Iter)?*vec_In_Iter:MAX;
        MIN = (MIN > *vec_In_Iter)?*vec_In_Iter:MIN;
        //If MAX(or MIN) is smaller(or bigger) than the next element, then 
        vec_In_Iter++;
    }
    //Sorting ELments
    //(Ayo Sort?, sot? shot?)->Om Prakash Mishra Reference😳😳???

    cout << "Output:\n";
    cout << "Smallest: " << MIN << endl << "Biggest: " << MAX;

    return 0;
}