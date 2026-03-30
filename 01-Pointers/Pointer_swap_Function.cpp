#include <iostream>
using namespace std;

// Creating function named "swap" for 2 pointers
// Create variable named "temp" to swap values of 2 pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    // Print the 2 values of the 2 variables
    cout << "A = " << *a << " , B = " << *b << endl;
}

int main () {
    int a = 5;      // Declare and initialize first variable
    int b = 10;     // Declare and initialize second variable

    // Call swap function (pass by Address)
    swap(&a, &b);

    return 0;
}