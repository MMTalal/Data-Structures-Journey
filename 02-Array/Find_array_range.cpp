#include <iostream>
using namespace std;

int main() {
    // Program title and description
    cout << "Find maximum and minimum numbers in your array and find the difference between them" << endl;
    
    // Ask user for array size
    cout << "What is your array size ?" << endl;

    int size;
    cin >> size;

    // Validate array size
    if (size <= 0)
    {
        cout << "Size cannot be less than or equal to zero!" << endl;
        return 1;
    }

    // Ask user for number of elements to enter
    cout << "How many elements do you want to enter ?" << endl;

    int length;
    cin >> length;

    // Validate length does not exceed size
    if (length > size)
    {
        cout << "Length cannot be greater than array size!" << endl;
        return 1;
    }

    // Dynamically allocate array on heap
    int* ptr = new int[size];

    // Variables to store minimum and maximum values
    int Minimum;
    int Maximum;

    // Input values and find min/max simultaneously
    for(int i = 0; i < length; i++)
    {
        cout << "What is the value of element No. " << i + 1 << endl; 
        cin >> ptr[i];

        // Initialize min and max with first element
        if (i == 0)
        {
            Maximum = Minimum = ptr[i];
        }
        else
        {
            // Update maximum if current element is larger
            if (ptr[i] > Maximum)
                Maximum = ptr[i];

            // Update minimum if current element is smaller
            if (ptr[i] < Minimum)
                Minimum = ptr[i];
        }
    }

    // Calculate difference between maximum and minimum
    int result = Maximum - Minimum;

    // Display the result
    cout << "Difference between " << Maximum << " and " << Minimum << " is " << result << endl;

    // Free allocated memory
    delete[] ptr;
    ptr = nullptr;

    return 0;
}