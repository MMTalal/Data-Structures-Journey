#include <iostream>
using namespace std;

// Define Node structure for linked list
struct Node {
    int Data;      // Value stored in the node
    Node* Next;    // Pointer to the next node
};

// Global pointer to the head of the linked list
Node* Head = nullptr;

// Function to insert a new node at the end of the list
void insert(int Data)
{
    Node* create = new Node();
    create->Data = Data;
    create->Next = nullptr;

    if(Head == nullptr)
    {
        Head = create;  // If list is empty, new node becomes head
    }
    else
    {
        // Traverse to the last node
        Node* temp = Head;
        while(temp->Next != nullptr)
        {
            temp = temp->Next;
        }
        temp->Next = create;  // Add new node at the end
    }
}

// Function to get user input and build the linked list
void userinput(int size)
{
    if (size < 0)
    {
        cout << "Size cannot be less than zero!" << endl;
    }
    else if (size == 0)
    {
        cout << "Your linked list is created but doesn't have any values" << endl;
        Node* nothing = new Node();
        Head = nothing;
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            cout << "What is the value for element No. " << i + 1 << endl;
            int value;
            cin >> value;
            insert(value);
        }
    }
}

// Function to display all elements in the linked list
void display(Node* Head)
{
    Node* temp = Head;
    while(temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }
}

// Function to search for a specific value in the linked list
void Search(int value)
{
    bool found = false;

    Node* search = Head;
    while(search != nullptr)
    {
        if(search->Data == value)
        {
            found = true;
            break;
        }
        search = search->Next;
    }

    if(found == true)
    {
        cout << "Value " << value << " is found in the linked list" << endl;
    }
    else
    {
        cout << "Value " << value << " is NOT found in the linked list" << endl;
    }
}

// Function to delete all nodes and free memory
void Clean(Node* Head)
{
    while(Head != nullptr)
    {
        Node* current = Head;
        Head = Head->Next;
        delete current;
    }
    Head = nullptr;
}

int main() {
    cout << "Let's search for a value in a linked list and discover if it's found or not" << endl;
    cout << "What is the size of your linked list?" << endl;

    int size;
    cin >> size;
    userinput(size);             

    cout << "Your linked list:" << endl;
    display(Head);

    cout << endl << "What is your target value to search for in the linked list? " << endl;
    int target;
    cin >> target;

    Search(target);
    Clean(Head);
    
    return 0;
}