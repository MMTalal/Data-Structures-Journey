#include <iostream>
using namespace std;

// Structure representing a single node in the stack
struct Node {
    int Data;      // Stores the value of the node
    Node* Next;    // Pointer to the next node
};

// Pointer to the top element of the stack
Node* Top = nullptr;

// Function to check if the stack is empty
bool IsEmpty()
{
    if(Top == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to push a new value into the stack
void Push(int Value)
{
    Node* NewNode = new Node();  // Create a new node dynamically
    NewNode->Data = Value;       // Assign value to the node
    if(IsEmpty() == true)        // If stack is empty
    {
        NewNode->Next = nullptr;
        Top = NewNode;
    }
    else
    {
        NewNode->Next = Top;         // Link new node to the current top
        Top = NewNode;               // Move top pointer to the new node
    }
}

// Function to display all stack elements
void Display()
{
    Node* temp = Top;            // Temporary pointer for traversal
    while(temp != nullptr)       // Traverse until the end of the stack
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }
    cout << endl;
}

// Function to get the top element without deleting it
int Peek()
{
    if(IsEmpty())     // Check if stack is empty
    {
        cout << "Your stack is empty" << endl;
        return -1;
    }
    else
    {
        return Top->Data;         // Return top element value
    }
}

// Function to remove the top element from the stack
void Pop()
{
    if(IsEmpty())     // Check if stack is empty
    {
        cout << "Your stack is empty" << endl;
    }
    else
    {
        Node* Del = Top;         // Store current top node
        Top = Top->Next;         // Move top pointer to the next node
        delete Del;              // Delete old top node
    }
}

// Function to search for a value inside the stack
bool IsFound(int Value)
{
    bool found = false;          // Flag to track if found
    Node* Search = Top;          // Pointer used for traversal

    while (Search != nullptr)
    {
        if (Search->Data == Value)         // Check if current node contains the target value
        {
            found = true;
            break;
        }
        Search = Search->Next;             // Move to the next node
    }

    if(found == true)     // Display search result
    {
        cout << "Your value is found" << endl;
    }
    else
    {
        cout << "Your value isn't found" << endl;
    }
    return found;
}

int main() {

    // Ask user to create the stack
    cout << "Create your stack now!" << endl;
    cout << "What is the size of your stack?" << endl;

    int size;
    cin >> size;

    int Value;
    int count = 0;     // Counter for stack elements
    if(size <= 0)      // Validate stack size
    {
        cout << "Size cannot be less than or equal to zero!" << endl;
        return 1;
    }
    else
    {
        for(int i = 0; i < size; i++)         // Insert elements into the stack
        {
            cout << "What is the value for element No. " << i + 1 << " in your stack?" << endl;
            cin >> Value;                     // Push value into stack
            Push(Value);
            count++;                          // Increase element counter

            cout << "Your element count for stack is " << count << endl;
            Display();                        // Display current stack
        }
    }

    // Ask user if they want to peek the top element
    cout << "Do you want to peek at the top element from your stack? (y/n)" << endl;

    string GetPeek;
    cin >> GetPeek;

    if (GetPeek == "y" || GetPeek == "Y")
    {
        cout << "Your top element is: " << Peek() << endl;
    }
    else if(GetPeek == "n" || GetPeek == "N")
    {
        cout << "You didn't choose to peek. Here is your stack without any changes" << endl;
    }
    else
    {
        cout << "You entered a wrong answer!" << endl;
        return 1;
    }

    // Ask user if they want to pop an element
    cout << "Do you want to pop an element from your stack? (y/n)" << endl;

    string GetPop;
    cin >> GetPop;

    if (GetPop == "y" || GetPop == "Y")
    {
        count--;
        cout << "You popped an element. Now there are " << count << " elements" << endl;
        Pop();         // Remove top element
        Display();     // Display updated stack
    }
    else if(GetPop == "n" || GetPop == "N")
    {
        cout << "You didn't choose to pop. Here is your stack without any changes" << endl;
    }
    else
    {
        cout << "You entered a wrong answer!" << endl;
        return 1;
    }

    // Ask user if they want to search for an element
    cout << "Do you want to search for any element in your stack? (y/n)" << endl;

    string GetSearch;
    cin >> GetSearch;

    if (GetSearch == "y" || GetSearch == "Y")
    {
        cout << "Enter your value to search for:" << endl;
        int SearchValue;
        cin >> SearchValue;
        IsFound(SearchValue);         // Search for the entered value
    }
    else if(GetSearch == "n" || GetSearch == "N")
    {
        cout << "You didn't choose to search. Here is your stack without any changes" << endl;
    }
    else
    {
        cout << "You entered a wrong answer!" << endl;
        return 1;
    }

    // Free all dynamically allocated nodes
    Node* Delete = Top;
    while(Top != nullptr)
    {
        Delete = Top;
        Top = Top->Next;
        delete Delete;
    }

    // Reset top pointer
    Top = nullptr;

    return 0;
}