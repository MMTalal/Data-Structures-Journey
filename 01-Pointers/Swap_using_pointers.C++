#include <iostream>
using namespace std;

int main() {
    // Creating 2 variables and assigning them values
    int X = 5;
    int Y = 10;
    
    // Print 2 variables
    cout << "X = " << X << " , Y = " << Y << endl;

    // Create 2 pointers for the 2 variables
    int *p = &X;
    int *q = &Y;
    
    // Print the 2 addresses using the pointers
    cout << "Address of X = " << &X << " , Address of Y = " << &Y << endl;

    // Assign values through pointers to swap the values of variables
    *p = 10;
    *q = 5;
    
    // Print the 2 variables after swapping values using pointers
    cout << "X = " << X << " , Y = " << Y << endl;
    
    return 0; 
}