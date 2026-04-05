#include <iostream>
using namespace std;

int main(){
    // Program description
    cout << "Input your values and get the smallest one of them" << endl;
    cout << "What is your array size ?" << endl;

    int size;
    cin >> size;

    // Validate array size
    if(size <= 0)
    {
        cout << "Error: Array size cannot be less than or equal to Zero!" << endl;
        return 1;
    }

    // Dynamically allocate array
    int *ptr = new int[size];

    int smallest;

    // Input values and find smallest
    for(int i = 0; i < size; i++)
    {
        cout << "What is the value of element no. " << i + 1 << " ?" << endl;
        cin >> ptr[i];
        
        // Initialize smallest with first element
        if (i == 0)
        {
            smallest = ptr[i];
        }
        else
        {
            // Update smallest if current element is smaller
            if (smallest > ptr[i])
            {
                smallest = ptr[i];
            }
        }
    }

    // Display result
    cout << "The smallest number you entered in the array is " << smallest << endl;

    // Free allocated memory
    delete[] ptr;
    ptr = nullptr;

    return 0;
}