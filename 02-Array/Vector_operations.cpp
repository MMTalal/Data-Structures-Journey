#include <iostream>
#include <vector>
using namespace std;

// Function to print vector elements
void print(const vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    // Program title
    cout << "Create vector and test it with a lot of operations" << endl;
    
    // Ask user for vector size
    cout << "What is the size of your vector?" << endl;

    int size;
    cin >> size;

    // Validate size
    if (size <= 0)
    {
        cout << "Size cannot be less than or equal to zero!" << endl;
        return 1;
    }

    // Create vector with given size
    vector<int> arr(size);

    // Input values from user
    for(int i = 0; i < arr.size(); i++)
    {
        cout << "What is the value for element No. " << i + 1 << endl;
        cin >> arr[i];
    }
    
    cout << "----------------------------------------------------" << endl;

    // Display vector elements
    cout << "Your vector elements are:" << endl;
    print(arr);
    
    // Display vector information
    cout << "Your vector size is: " << arr.size() << endl;

    // Display first element if vector is not empty
    if(!arr.empty())
    {
        cout << "Your first element in vector is: " << arr.front() << endl;
    }

    // Display last element
    if(arr.size() > 0)
    {
        cout << "Your last element in vector is: " << arr[arr.size() - 1] << endl;
    }

    // Get element by position
    cout << "Which element position do you want to retrieve?" << endl;
    int get;
    cin >> get;

    // Validate position
    if (get > arr.size() || get <= 0)
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
        print(arr);
    }
    else if(change == "y" || change == "Y" || change == "Yes" || change == "yes")
    {
        // Ask which element to modify
        cout << "Which element number do you want to change?" << endl;
        int element;
        cin >> element;

        // Validate element number
        if (element <= 0 || element > arr.size())
        {
            cout << "Invalid element number!" << endl;
            return 1;
        }

        // Get new value
        cout << "What is the new value for this element?" << endl;
        int value;
        cin >> value;

        if (arr[element - 1] == value)
        {
            cout << "Value is already " << value << endl;
        }
        else
        {
            // Update element
            arr[element - 1] = value;
            cout << "Updated successfully.. element No. " << element << " changed to " << value << endl;
            cout << "Your vector after modification:" << endl;
            print(arr);
        }
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }
    
    // Ask user if they want to resize the vector
    cout << "Do you want to resize your vector? (y/n)" << endl;
    string resize;
    cin >> resize;

    if(resize == "n" || resize == "N" || resize == "No" || resize == "no")
    {
        cout << "OK, your vector size remains unchanged" << endl;
        cout << "Vector size is still: " << arr.size() << endl;
    }
    else if(resize == "y" || resize == "Y" || resize == "Yes" || resize == "yes")
    {
        // Ask for new size
        cout << "What is the new size for your vector?" << endl;
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

        cout << "Vector size changed to: " << arr.size() << endl;    
        cout << "Vector elements after resize:" << endl;
        print(arr);
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }

    // Add new element at the end
    cout << "Do you want to add a new element to your vector? (y/n)" << endl;
    string add;
    cin >> add;

    if(add == "n" || add == "N" || add == "No" || add == "no")
    {
        cout << "OK, your vector size remains unchanged" << endl;
        cout << "Vector size is still: " << arr.size() << endl;
        print(arr);
    }
    else if(add == "y" || add == "Y" || add == "Yes" || add == "yes")
    {
        // Ask for value to add
        cout << "What is the value of the new element?" << endl;
        int addValue;
        cin >> addValue;
        arr.push_back(addValue);        
        cout << "Vector size changed to: " << arr.size() << endl; 
        print(arr);
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }

    // Remove last element
    cout << "Do you want to remove the last element from your vector? (y/n)" << endl;
    string remove;
    cin >> remove;

    if(remove == "n" || remove == "N" || remove == "No" || remove == "no")
    {
        cout << "OK, your vector size remains unchanged" << endl;
        cout << "Vector size is still: " << arr.size() << endl;
        print(arr);
    }
    else if(remove == "y" || remove == "Y" || remove == "Yes" || remove == "yes")
    {
        if (arr.empty())
        {
            cout << "Your vector is already empty!" << endl;
            return 1;
        }
        else
        {
            arr.pop_back();        
            cout << "Vector size changed to: " << arr.size() << endl; 
            print(arr);
        }
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }

    // Erase specific element
    cout << "Do you want to erase any element from your vector? (y/n)" << endl;
    string erase;
    cin >> erase;

    if(erase == "n" || erase == "N" || erase == "No" || erase == "no")
    {
        cout << "OK, your vector size remains unchanged" << endl;
        cout << "Vector size is still: " << arr.size() << endl;
        print(arr);
    }
    else if(erase == "y" || erase == "Y" || erase == "Yes" || erase == "yes")
    {
        // Ask which element to erase
        cout << "Which element number do you want to erase?" << endl;
        int eraseValue;
        cin >> eraseValue;

        if (eraseValue <= 0 || eraseValue > arr.size())
        {
            cout << "Invalid element number!" << endl;
            return 1;
        }

        arr.erase(arr.begin() + (eraseValue - 1)); 
        cout << "Vector size changed to: " << arr.size() << endl; 
        print(arr);
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }

    // Insert element at specific position
    cout << "Do you want to insert an element into your vector? (y/n)" << endl;
    string insert;
    cin >> insert;

    if(insert == "n" || insert == "N" || insert == "No" || insert == "no")
    {
        cout << "OK, your vector size remains unchanged" << endl;
        cout << "Vector size is still: " << arr.size() << endl;
        print(arr);
    }
    else if(insert == "y" || insert == "Y" || insert == "Yes" || insert == "yes")
    {
        // Ask for position
        cout << "At which position do you want to insert?" << endl;
        int insertIndex;
        cin >> insertIndex;

        // Ask for value
        cout << "What is the value of the element to insert?" << endl;
        int insertValue;
        cin >> insertValue;

        if (insertIndex <= 0 || insertIndex > arr.size() + 1)
        {
            cout << "Invalid position!" << endl;
            return 1;
        }
        
        arr.insert(arr.begin() + (insertIndex - 1), insertValue); 
        cout << "Vector size changed to: " << arr.size() << endl; 
        print(arr);
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }

    // Clear the entire vector
    cout << "Do you want to clear your vector? (y/n)" << endl;
    string clear;
    cin >> clear;

    if(clear == "n" || clear == "N" || clear == "No" || clear == "no")
    {
        cout << "OK, your vector size remains unchanged" << endl;
        cout << "Vector size is still: " << arr.size() << endl;
        print(arr);
    }
    else if(clear == "y" || clear == "Y" || clear == "Yes" || clear == "yes")
    {
        cout << "Your vector is now cleared!" << endl;
        arr.clear();
        cout << "Vector size changed to: " << arr.size() << endl;
        cout << "Thank you!" << endl;    
    }
    else
    {
        cout << "Invalid answer!" << endl;
        return 1;
    }

    return 0;
}