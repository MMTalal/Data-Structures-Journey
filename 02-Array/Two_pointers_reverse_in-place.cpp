#include <iostream>
using namespace std;

int main() {

    cout << "Input your array values and I'll reverse it" << endl;
    cout << "What is your array size ?" << endl;

    int size;
    cin >> size;

    if (size <= 0)
    {
        cout << "Your size cannot be less than or equal to Zero!" << endl;
        return 1;
    }

    cout << "How many elements do you want to enter ?" << endl;

    int length;
    cin >> length;

    if (length > size)
    {
        cout << "Length cannot be greater than array size!" << endl;
        return 1;
    }

    // Dynamically allocate array
    int* ptr = new int[size];

    // Input values from user
    for(int i = 0; i < length; i++)
    {
        cout << "What is your value for element No. " << i + 1 << endl;
        cin >> ptr[i];
    }

    // Reverse the array using two pointers
    int left = 0;
    int right = length - 1;

    while (left < right)
    {
        // Swap elements at left and right positions
        int temp = ptr[right];
        ptr[right] = ptr[left];
        ptr[left] = temp;

        left++;
        right--;
    }

    // Print reversed array
    cout << "Reversed array:" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << ptr[i] << endl;
    }

    // Free allocated memory
    delete[] ptr;
    ptr = nullptr;

    return 0;
}