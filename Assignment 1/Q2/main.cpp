/*
    Name: Aaditya J.
    Pixels Ass1_Q2
*/
#include <iostream>

int main()
{
    int a, * pointer = &a;
    //Initialize pointer to point at a location(in this case a itself)
    a = (int) pointer;
    //Store the value of pointer in 'a'
    pointer--;
    //Decrement so that pointer points to "previous" integer
    a -= (int) pointer;
    //Subtract new value of pointer from original

    std::cout << "The size of datatype int is: " << a;

    return 0;
}