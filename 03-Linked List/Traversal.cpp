#include <iostream>
using namespace std;

// Define a Node structure for linked list
struct Node
{
    int Data;      // Value stored in the node
    Node* Next;    // Pointer to the next node
};

// Global pointer to the head of the linked list
Node* Head = nullptr;

int main() {

    // Create 5 nodes dynamically on the heap
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();
    Node* d = new Node();
    Node* e = new Node();
    
    // Link nodes together and assign values
    a->Data = 1;
    a->Next = b;

    b->Data = 2;
    b->Next = c;

    c->Data = 3;
    c->Next = d;

    d->Data = 4;
    d->Next = e;

    e->Data = 5;
    e->Next = nullptr;  // Last node points to null

    // Set head to point to first node
    Head = a;

    // Temporary pointer to traverse the list
    Node* temp = Head;

    // Traverse the linked list
    while(temp != nullptr)
    {
        cout << temp->Data << " ";  // Print current node's data
        temp = temp->Next;          // Move to next node
    }

    // Delete all nodes from Linked List
    while (Head != nullptr)
    {
        Node* temp = Head;          // Store current head in temp
        Head = Head->Next;          // Move head to the next node
        delete temp;                // Delete the old head node
    }

    // Make Head a null pointer
    Head = nullptr;

    return 0;
}