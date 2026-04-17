#include <iostream>
#include <vector>
using namespace std;

int main () {
    // Program title and description
    cout << "Search for two values in your array that sum to target value" << endl;
    
    // Ask user for array size
    cout << "What is your array size ?" << endl;

    int size;
    cin >> size;

    // Validate array size
    if (size <= 0)
    {
        cout << "Size cannot be less than or equal to Zero!" << endl;
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

    // Create vector (dynamic array) of given size
    vector<int> arr(size);

    // Input values from user
    for (int i = 0; i < length; i++)
    {
        cout << "What is the value of element No. " << i + 1 << " ?" << endl;
        cin >> arr[i];
    }

    // Ask user for target value to search for
    cout << "Now.. What is your target value ?" << endl;

    int target;
    cin >> target;

    // Variables to store the two elements that sum to target
    int firstElement;
    int secondElement;
    bool found = false;

    // Find two elements that sum to target using nested loops
    for (int i = 0; i < length; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            // Check if current pair sums to target
            if(arr[i] + arr[j] == target)
            {
                found = true;
                firstElement = arr[i];
                secondElement = arr[j];
                break;  // Exit inner loop
            }
        }
        if (found == true)
        {
            break;  // Exit outer loop
        }
    }

    // Display result
    if (found == true)
    {
        cout << "Target " << target << " is the sum of " << firstElement << " and " << secondElement << endl;
    }
    else
    {
        cout << "Target cannot be obtained by summing any two elements in the array" << endl;
    }
    
    return 0;
}