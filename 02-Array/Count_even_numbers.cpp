#include <iostream>
using namespace std;

int main () {
    cout << "Input your values and get the number of even numbers among them" << endl;

    cout << "What is your array size ?" << endl;

    int size;
    cin >> size;

    if (size <= 0)
    {
        cout << "Size of your array cannot be less than or equal to Zero!" << endl;
        return 1;
    }

    cout << "How many elements do you want to enter ?" << endl;

    int length;
    cin >> length;

    if (length > size)
    {
        cout << "Length of your array cannot be greater than size!" << endl;
        return 1;
    }

    // Dynamically allocate array
    int *ptr = new int[size];

    int evenCount = 0;

    // Input values and count even numbers
    for(int i = 0; i < length; i++)
    {
        cout << "What is the value of Element No. " << i + 1 << endl;
        cin >> ptr[i];
        if (ptr[i] % 2 == 0) 
        {
            evenCount = evenCount + 1;
        }
    }

    // Display results
    if(evenCount == 0)
    {
        cout << "You do not have any even numbers in your array!" << endl;
    }
    else
    {
        cout << "The size of your array is " << size << " and the length is " << length << " and the number of even numbers is " << evenCount << endl;
        cout << "Even numbers are: [ ";

        for(int i = 0; i < length; i++)
        {
            if (ptr[i] % 2 == 0)
            {
                cout << ptr[i] << " ";
            } 
        }

        cout << "]" << endl;
    }

    // Free allocated memory
    delete[] ptr;
    ptr = nullptr;

    return 0;
}