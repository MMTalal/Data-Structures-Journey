#include <iostream>
using namespace std;

int main(){
    // Ask user for array size
    cout << "How many size do you want for Array ?" << endl;
    int size;
    cin >> size;    

    // Ask user for number of elements they want to enter
    cout << "How many elements do you want to enter ?" << endl;
    int length;
    cin >> length;

    // Dynamically allocate array of given size
    int* ptr = new int[size];

    int sum = 0;

    // Check if length exceeds array size
    if (length > size)
    {
        cout << "You cannot choose length bigger than array size" << endl;
        delete[] ptr;
        ptr = nullptr;
        return 1;
    }
    else
    {
        cout << "Now you can fill your array values" << endl;
        
        // Input values from user
        for(int i = 0; i < length; i++)
        {
            cout << "What is your value for element no. " << i + 1 << " ?" << endl;
            cin >> ptr[i];
            sum = sum + ptr[i];
        }

    cout << "You entered " << length << " elements out of " << size << " array size" << endl;

        // Display array values
        cout << "Your array values are:" << endl;
        for(int i = 0; i < length; i++)
        {
            cout << ptr[i] << endl;
        }

        cout << "----------" << endl;
        cout << "Summation of values you entered is " << sum << endl;
    }

    // Free allocated memory
    delete[] ptr;
    ptr = nullptr; 

    return 0;
}