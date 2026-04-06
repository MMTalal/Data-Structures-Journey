#include <iostream>
using namespace std;

int main () {

    cout << "What is your array size ?" << endl;

    int size;
    cin >> size;

    int length;

    // Validate array size
    if (size <= 0)
    {
        cout << "Array size cannot be less than or equal to Zero!" << endl;
        return 1;
    }

    // Dynamically allocate array
    int* ptr = new int[size];

    cout << "How many elements do you want to enter ?" << endl;
    cin >> length;

    // Validate length
    if (length > size)
    {
        cout << "Length cannot be greater than array size!" << endl;
        delete[] ptr;
        ptr = nullptr;
        return 1;
    }

    // Input array elements
    for (int i = 0; i < length; i++)
    {
        cout << "What is your value for element No. " << i + 1 << " ?" << endl;
        cin >> ptr[i];
    }
    
    // Ask user for target to search
    cout << "Now enter the number you want to search for in your array" << endl;
    int target;
    cin >> target;

    // Linear search for target
    int foundIndex = -1;

    for(int i = 0; i < length; i++)
    {
        if (target == ptr[i])
        {
            foundIndex = i;
            break;
        }
    }

    // Display result
    if (foundIndex != -1)
    {
        cout << "Target " << target << " found at index " << foundIndex << endl;
    }
    else
    {
        cout << "Target is not found" << endl; 
    }

    // Free allocated memory
    delete[] ptr;
    ptr = nullptr;

    return 0;
}