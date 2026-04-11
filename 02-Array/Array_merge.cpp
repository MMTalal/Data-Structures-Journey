#include <iostream>
using namespace std;

int main() {
    // Program title and description
    cout << "Input two arrays and the program will merge them in sorted order" << endl;
    
    // ==================== FIRST ARRAY ====================
    cout << "What is the size of the first array ?" << endl;

    int size1;
    cin >> size1;

    // Validate array size
    if (size1 <= 0)
    {
        cout << "Size of first array cannot be less than or equal to zero!" << endl;
        return 1;
    }

    // Dynamically allocate first array
    int* ptr1 = new int[size1];

    cout << "How many elements do you want to enter in the first array ?" << endl;

    int length1;
    cin >> length1;

    // Validate length does not exceed size
    if (length1 > size1)
    {
        cout << "Length of first array cannot be greater than its size!" << endl;
        return 1;
    }

    // Input elements for first array (must be ascending order)
    for(int i = 0; i < length1; i++)
    {
        cout << "What is the value for element No. " << i + 1 << " in the first array ?" << endl;
        cin >> ptr1[i];

        // Check if values are entered in ascending order
        if (i > 0 && ptr1[i - 1] > ptr1[i])
        {
            cout << "You must enter values in ascending order!" << endl;
            return 1;
        }
    }

    // ==================== SECOND ARRAY ====================
    cout << "What is the size of the second array ?" << endl;

    int size2;
    cin >> size2;

    // Validate array size
    if (size2 <= 0)
    {
        cout << "Size of second array cannot be less than or equal to zero!" << endl;
        return 1;
    }

    // Dynamically allocate second array
    int* ptr2 = new int[size2];

    cout << "How many elements do you want to enter in the second array ?" << endl;

    int length2;
    cin >> length2;

    // Validate length does not exceed size
    if (length2 > size2)
    {
        cout << "Length of second array cannot be greater than its size!" << endl;
        return 1;
    }

    // Input elements for second array (must be ascending order)
    for(int j = 0; j < length2; j++)
    {
        cout << "What is the value for element No. " << j + 1 << " in the second array ?" << endl;
        cin >> ptr2[j];

        // Check if values are entered in ascending order
        if (j > 0 && ptr2[j - 1] > ptr2[j])
        {
            cout << "You must enter values in ascending order!" << endl;
            return 1;
        }
    }

    // ==================== DISPLAY BOTH ARRAYS ====================
    cout << "Your values of first array are:" << endl;
    for (int i = 0; i < length1; i++)
    {
        cout << ptr1[i] << " ";
    }

    cout << endl << "Your values of second array are:" << endl;
    for (int j = 0; j < length2; j++)
    {
        cout << ptr2[j] << " ";
    }

    // ==================== MERGE TWO SORTED ARRAYS ====================
    // Allocate memory for merged array (size of both arrays combined)
    int* ptr3 = new int[size1 + size2];

    int i = 0;  // Index for first array
    int j = 0;  // Index for second array
    int k = 0;  // Index for merged array

    // Merge both arrays in sorted order (like merging in merge sort)
    while (i < length1 && j < length2)
    {
        if (ptr1[i] < ptr2[j])
        {
            ptr3[k] = ptr1[i];  // Take element from first array
            i++;
        }
        else
        {
            ptr3[k] = ptr2[j];  // Take element from second array
            j++;
        }
        k++;
    }

    // Copy remaining elements from first array (if any)
    while (i < length1)
    {
        ptr3[k] = ptr1[i];
        i++;
        k++;
    }

    // Copy remaining elements from second array (if any)
    while (j < length2)
    {
        ptr3[k] = ptr2[j];
        j++;
        k++;
    }

    // ==================== DISPLAY MERGED ARRAY ====================
    cout << endl << "Your arrays merged in sorted order are:" << endl;
    for(int k = 0; k < (length1 + length2); k++)
    {
        cout << ptr3[k] << " ";
    }
    cout << endl;

    // ==================== FREE ALLOCATED MEMORY ====================
    delete[] ptr1;
    ptr1 = nullptr;

    delete[] ptr2;
    ptr2 = nullptr;

    delete[] ptr3;
    ptr3 = nullptr;
    
    return 0;
}