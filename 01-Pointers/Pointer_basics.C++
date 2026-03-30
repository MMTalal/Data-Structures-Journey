#include <iostream>
using namespace std;

int main() {
    // Creating variable named "x" assigned to 10
    int x = 10;
    // Print it
    cout << "Value of x = " << x << endl;

    // Creating pointer named "p" assigned to the address of x
    int* p = &x;
    // Print x address using the pointer
    cout << "Address of x = " << &x << endl;
    
    // Print x value using the pointer
    cout << "Value of x using its pointer = " << *p << endl;
    // Assign 20 to the value pointed to by p (which is x)
    *p = 20;
    // Print x address again (address does not change)
    cout << "Address of x after we change its value = " << &x << endl;

    // Print x value again after modifying it through the pointer
    cout << "New value of x after we assign its pointer = " << x << endl; // Output of x becomes 20
    
    return 0;
}