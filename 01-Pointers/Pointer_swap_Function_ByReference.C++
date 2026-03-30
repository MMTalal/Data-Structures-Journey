#include <iostream>
using namespace std;

// Function to swap two integers using references
// Uses a temporary variable to store value before swapping
void swap(int &a, int &b) {
    int temp = a;  // Store original value of a
    a = b;         // Assign b's value to a
    b = temp;      // Assign stored value to b
    
    // Print values after swapping
    cout << "A = " << a << " , B = " << b << endl;
}

int main () {
    int a = 10;  // Declare and initialize first variable
    int b = 50;  // Declare and initialize second variable
    
    // Print original values
    cout << "A = " << a << " , B = " << b << endl;
    
    // Call swap function (pass by reference)
    swap(a, b);
    
    return 0;
}