#include <iostream>
using namespace std;

int main(){
    
    // Ask user to enter the size of the array
    cout << "Choose number please" << endl;

    int n;
    cin >> n;
    
    // Dynamically allocate array of size n on the heap
    int* arr = new int[n];
    
    // Input values from user and store in array
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int sum = 0;

    // Print each value and calculate the sum
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
        sum = sum + arr[i];
    }
    
    // Display the total sum
    cout << "Sum of numbers you chose is " << sum << endl;
    
    // Free the dynamically allocated array memory
    delete[] arr;
    // Prevent dangling pointer
    arr = nullptr;
    
    return 0;
}