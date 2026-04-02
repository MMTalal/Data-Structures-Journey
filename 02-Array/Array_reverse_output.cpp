#include <iostream>
using namespace std;

int main (){
    // Declare a static array of 5 integers
    int arr[5];

    // Input 5 values from user
    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    // Print the array in reverse order (from last index to first)
    for(int i = 4; i >= 0; i--)
    {
        cout << arr[i] << endl;
    }

    return 0;
}