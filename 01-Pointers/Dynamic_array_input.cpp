#include <iostream>
using namespace std;

int main() {
    // Dynamically allocate array of 3 integers on the heap
    int* arr = new int[3];
    
    // Input values from user and store in array
    for(int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    
    // Output the stored values
    for(int i = 0; i < 3; i++)
    {
        cout << arr[i] << endl;
    }
    
    // Free the dynamically allocated array memory
    delete[] arr;
    // Prevent dangling pointer
    arr = nullptr;

    return 0;
}