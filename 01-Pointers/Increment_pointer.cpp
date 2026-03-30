#include <iostream>
using namespace std;

// Function to add 1 to the value pointed to by p
void addOne(int* p) 
{
    // Increment the value by 1 using dereferencing
    *p = *p + 1;
    
    // Print the new value
    cout << *p << endl;
}

int main() {
    // Dynamically allocate memory for an integer and initialize to 5
    int* x = new int(5);
    
    // Pass the pointer to the function
    addOne(x);
    
    // Free allocated memory
    delete x;
    
    // Prevent dangling pointer
    x = nullptr;
    
    return 0;
}