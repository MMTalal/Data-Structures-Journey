#include <iostream>
using namespace std;

int main () {
    // Print program title and description
    cout << "Clean your array from duplicates" << endl;
    
    // Ask user for maximum array size
    cout << "What is your array size ?" << endl;

    int size;
    cin >> size;

    // Validate array size (must be positive)
    if (size <= 0)
    {
        cout << "Your size cannot be less than or equal to Zero!";
        return 1;
    }

    // Ask user for number of elements to enter
    cout << "What is your array length ?" << endl;

    int length;
    cin >> length;

    // Validate length does not exceed size
    if (length > size)
    {
        cout << "Your length cannot be greater than your size!";
        return 1;
    }

    // Dynamically allocate array on heap
    int* ptr = new int[size];

    // Input values from user
    for(int i = 0; i < length; i++)
    {
        cout << "What is value for the element No. " << i + 1 << " ?" << endl;
        cin >> ptr[i];
    }

    // Print array after removing duplicates
    cout << "Your array after cleaning is ";

    // Loop through array and print non-duplicate elements
    // Note: This method only works if array is sorted
    for(int i = 0; i < length; i++)
    {
        // Print element if it's zero OR different from previous element
        if(ptr[i] == 0 || ptr[i] != ptr[i-1])
        {
            cout << ptr[i] << " ";
        }
    }

    // Free dynamically allocated memory
    delete[] ptr;
    // Prevent dangling pointer
    ptr = nullptr;

    return 0;
}