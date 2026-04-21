#include <iostream>
using namespace std;

// Define Node structure for linked list
struct Node {
    int Data;      // Value stored in the node
    Node* Next;    // Pointer to the next node
};

// Global pointer to the head of the linked list
Node* Head = nullptr;

// Recursive function to print linked list in reverse order
void PrintReverse(Node* Node)
{
    // Base case: if node is null, stop recursion
    if(Node == nullptr)
    {
        return;
    }
    // Recursive call: go to the next node first
    PrintReverse(Node->Next);
    // Print current node's data after returning from recursion
    cout << Node->Data << " ";
}

int main() {
    cout << "Let's build a linked list together" << endl;
    cout << "What is the size of your linked list? " << endl;

    int size;
    cin >> size;

    // Validate size
    if (size <= 0)
    {
        cout << "Size cannot be less than or equal to Zero!" << endl;
        return 1;
    }

    Node* temp = nullptr;

    // Create linked list by taking user input
    for (int i = 0; i < size; i++)
    {
        cout << "What is the value of element No. " << i + 1 << endl;
        Node* newNode = new Node();
        newNode->Next = nullptr;
        
        cin >> newNode->Data;

        // If list is empty, set head to first node
        if(Head == nullptr)
        {
            Head = newNode;
            temp = newNode;
        }
        else
        {
            // Add new node to the end of the list
            temp->Next = newNode;
            temp = newNode;
        }
    }

    // Print linked list in normal order
    cout << "Your linked list:" << endl;
    Node* current = Head;

    while(current != nullptr)
    {
        cout << current->Data << " ";
        current = current->Next;
    }

    // Print linked list in reverse order using recursion
    cout << endl << "Now.. print values in reverse order:" << endl;
    PrintReverse(Head);
    cout << endl;

    // Delete all nodes to free memory and prevent memory leak
    while(Head != nullptr)
    {
        Node* temp = Head;
        Head = Head->Next;
        delete temp;
    }
    Head = nullptr;

    return 0;
}