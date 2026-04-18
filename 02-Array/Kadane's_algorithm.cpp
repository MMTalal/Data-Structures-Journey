#include <iostream>
#include <vector>
using namespace std;

int main () {
    // Program title and description
    cout << "Input your array and get the maximum subarray sum using Kadane's Algorithm" << endl;
    
    // Ask user for array size
    cout << "What is your array size ?" << endl;

    int size;
    cin >> size;

    // Validate array size
    if (size <= 0)
    {
        cout << "Array size cannot be less than or equal to zero!" << endl;
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

    // Create vector of given size
    vector<int> arr(size);

    // Input values from user
    for (int i = 0; i < length; i++)
    {
        cout << "What is the value for element No. " << i + 1 << endl;
        cin >> arr[i];
    }

    // Initialize Kadane's Algorithm with first element
    int currentSum = arr[0];  // Sum of current subarray
    int maxSum = arr[0];      // Maximum sum found so far

    // Apply Kadane's Algorithm
    for (int i = 1; i < length; i++)
    {
        // Either extend existing subarray or start new subarray from current element
        currentSum = max(arr[i], currentSum + arr[i]);

        // Update maxSum if we found a larger sum
        maxSum = max(maxSum, currentSum);
    }

    // Display the result
    cout << "Maximum subarray sum is " << maxSum << endl;

    return 0;
}