#include <iostream>
using namespace std;

// Define Node structure for linked list
struct Node {
    int Data;      // Value stored in the node
    Node* Next;    // Pointer to the next node
};

// Global pointer to the head of the linked list
Node* Head = nullptr;

int main() {
    cout << "This is a linked list, and you will choose a number to append it at the front" << endl;

    // Create 3 nodes manually
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();

    // Assign values and link nodes
    a->Data = 5;
    a->Next = b;

    b->Data = 10;
    b->Next = c;

    c->Data = 15;
    c->Next = nullptr;

    // Set head to point to first node
    Head = a;

    // Print original list
    cout << "Original list:" << endl;
    Node* temp = Head;

    while(temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }

    // Ask user for new value
    cout << endl << "What is the new value you want to append at the front of the list?" << endl;

    int newValue;
    cin >> newValue;

    // Create new node and insert at the beginning
    Node* newNode = new Node();
    newNode->Data = newValue;
    newNode->Next = Head;  // New node points to old head
    Head = newNode;        // Update head to new node

    // Print list after insertion
    cout << "The new list after appending at the front is:" << endl;
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
        Node* temp = Head;
        Head = Head->Next;
        delete temp;
    }

    Head = nullptr;

    return 0;
}