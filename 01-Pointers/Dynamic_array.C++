#include <iostream>
using namespace std;

int main() {
    // Dynamically allocate array of 5 integers on the heap
    int* arr = new int[5];

    // Fill the array with values 1 to 5 and print them
    for(int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;      // Assign values 1, 2, 3, 4, 5
        cout << arr[i] << endl;  // Print each value
    }

    // Free the dynamically allocated array memory
    delete[] arr;
    
    // Prevent dangling pointer
    arr = nullptr;

    return 0;
}