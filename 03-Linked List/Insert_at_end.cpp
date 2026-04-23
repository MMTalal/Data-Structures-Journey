#include <iostream>
using namespace std;

// Define Node structure for linked list
struct Node {
    int Data;      // Value stored in the node
    Node* Next;    // Pointer to the next node
};

// Global pointer to the head of the linked list
Node* Head = nullptr;

int main () {
    cout << "Let's build a linked list and append a new element at the back" << endl;

    // Create 3 nodes manually
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();

    // Assign values and link nodes
    a->Data = 1;
    a->Next = b;

    b->Data = 2;
    b->Next = c;

    c->Data = 3;
    c->Next = nullptr;

    // Set head to point to first node
    Head = a;

    // Print original list
    cout << "The linked list values before insertion:" << endl;
    Node* temp = Head;
    while(temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }

    // Ask user for new value
    cout << endl << "Now.. what is the new value you want to append at the back?" << endl;
    int newValue;
    cin >> newValue;

    // Create new node
    Node* d = new Node();
    d->Data = newValue;
    d->Next = nullptr;

    // Traverse to the last node
    Node* append = Head;
    while(append->Next != nullptr)
    {
        append = append->Next;
    }

    // Append new node at the end
    append->Next = d;

    // Print list after insertion
    cout << "The linked list values after insertion:" << endl;
    Node* current = Head;
    while(current != nullptr)
    {
        cout << current->Data << " ";
        current = current->Next;
    }
    cout << endl;

    // Delete all nodes to free memory
    while(Head != nullptr)
    {
        Node* del = Head;
        Head = Head->Next;
        delete del;
    }

    Head = nullptr;

    return 0;
}