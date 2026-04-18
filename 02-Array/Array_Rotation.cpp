#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a portion of the array from index 'left' to 'right'
void reverse(int* arr, int left, int right)
{
    while (left < right)
    {
        // Swap elements at left and right positions
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int main() {
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

    // Create vector of given size
    vector<int> arr(size);

    // Input values from user
    for(int i = 0; i < length; i++)
    {
        cout << "What is the value for element No. " << i + 1 << " ?" << endl;
        cin >> arr[i];
    }

    // Ask user for number of positions to rotate
    cout << "How many positions do you want to rotate the array?" << endl;
    int rotate;
    cin >> rotate;

    // Validate rotate value
    if (rotate >= length)
    {
        cout << "Cannot rotate array! Rotate value must be less than array length" << endl;
        return 1;
    }

    // Step 1: Reverse entire array
    reverse(arr.data(), 0, length - 1);                             //arr.data() = &arr[0]

    // Step 2: Reverse first No. of elements
    reverse(arr.data(), 0, rotate - 1);

    // Step 3: Reverse remaining elements
    reverse(arr.data(), rotate, length - 1);

    cout << "Array after rotation: ";

    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}