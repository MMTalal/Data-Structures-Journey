#include <iostream>
#include <vector>
using namespace std;

int main () {
    // Program title
    cout << "Create vector and test it" << endl;
    
    // Ask user for vector capacity (size)
    cout << "What is the capacity of your vector?" << endl;

    int size;
    cin >> size;

    // Validate size
    if (size <= 0)
    {
        cout << "Size cannot be less than or equal to zero!" << endl;
        return 1;
    }

    // Ask user for number of elements to add (length)
    cout << "How many elements do you want to add?" << endl;

    int length;
    cin >> length;

    // Validate length
    if (length > size)
    {
        cout << "Length cannot be greater than vector capacity!" << endl;
        return 1;
    }

    // Create vector with given capacity
    vector<int> arr(size);

    // Input values from user
    for(int i = 0; i < length; i++)
    {
        cout << "What is the value for element No. " << i + 1 << endl;
        cin >> arr[i];
    }
    
    cout << "----------------------------------------------------" << endl;

    // Display vector elements
    cout << "Your vector elements are:" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Display vector information
    cout << "Your vector length (used elements) is: " << length << endl;
    cout << "Your vector capacity is: " << arr.size() << endl;

    // Display first element if vector is not empty
    if(!arr.empty())
    {
        cout << "Your first element in vector is: " << arr.front() << endl;
    }

    // Display last element
    if(length > 0)
    {
        cout << "Your last element in vector is: " << arr[length - 1] << endl;
    }

    // Get element by position
    cout << "Which element position do you want to retrieve?" << endl;
    int get;
    cin >> get;

    // Validate position
    if (get > length || get <= 0)
    {
        cout << "Element not found!" << endl;
        return 1;
    }

    cout << "The value of element No. " << get << " is: " << arr[get - 1] << endl;

    // Ask user if they want to modify an element
    cout << "Do you want to change a value in your vector? (y/n)" << endl;
    string change;
    cin >> change;

    if(change == "n" || change == "N" || change == "No" || change == "no")
    {
        cout << "OK, your vector remains unchanged:" << endl;
        for(int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else if(change == "y" || change == "Y" || change == "Yes" || change == "yes")
    {
        // Ask which element to modify
        cout << "Which element number do you want to change?" << endl;
        int element;
        cin >> element;

        // Validate element number
        if (element <= 0 || element > length)
        {
            cout << "Invalid element number!" << endl;
            return 1;
        }

        // Get new value
        cout << "What is the new value for this element?" << endl;
        int value;
        cin >> value;

        // Update element
        arr[element - 1] = value;
        cout << "Element No. " << element << " changed to " << value << endl;
        cout << "Your vector after modification:" << endl;
        for(int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }

    cout << endl;
    
    // Ask user if they want to resize the vector
    cout << "Do you want to resize your vector? (y/n)" << endl;
    string resize;
    cin >> resize;

    if(resize == "n" || resize == "N" || resize == "No" || resize == "no")
    {
        cout << "OK, your vector capacity remains unchanged" << endl;
        cout << "Vector capacity is still: " << arr.size() << endl;
    }
    else if(resize == "y" || resize == "Y" || resize == "Yes" || resize == "yes")
    {
        // Ask for new size
        cout << "What is the new capacity for your vector?" << endl;
        int newSize;
        cin >> newSize;

        // Validate new size
        if(newSize < 0)
        {
            cout << "Invalid size!" << endl;
            return 1;
        }

        // Resize the vector
        arr.resize(newSize);
        length = arr.size();

        cout << "Vector capacity changed to: " << arr.size() << endl;    
        cout << "Vector elements after resize:" << endl;
        
        for(int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }

    return 0;
}