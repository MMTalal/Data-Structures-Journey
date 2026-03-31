#include <iostream>
using namespace std;

// This function takes an integer and adds 10 to it using a pointer
void PlusTen(int x)
{
    // Create a pointer that points to a dynamically allocated integer with value x
    int* p = new int(x);
    
    // Add 10 to the value using the pointer and store in x
    x = *p + 10;
    
    // Print the original value (before adding 10)
    cout << "Number you chose before adding 10 is: " << *p << endl;
    
    // Print the new value after adding 10
    cout << "Number you chose after adding 10 is: " << x << endl;
    
    // Free the dynamically allocated memory
    delete p;
    // Prevent dangling pointer
    p = nullptr;
}

int main() {
    // Print request message
    cout << "Choose any number and I will add 10 to it (Using pointer)" << endl;
    
    // Create variable and read it from user
    int n;
    cin >> n;

    // Call the function
    PlusTen(n);
    
    return 0;
}