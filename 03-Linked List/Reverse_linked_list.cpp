#include<iostream>
using namespace std;

struct Node {
    int Data;
    Node* Next;
};

Node* Head = nullptr;

int main() {
    cout << "This is a linked list of 5 elements" << endl;
    
    // Create 5 nodes manually
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();
    Node* d = new Node();
    Node* e = new Node();

    // Link nodes together
    a->Data = 1;
    a->Next = b;

    b->Data = 2;
    b->Next = c;

    c->Data = 3;
    c->Next = d;

    d->Data = 4;
    d->Next = e;

    e->Data = 5;
    e->Next = nullptr;

    Head = a;

    // Display original list
    Node* temp = Head;
    while (temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }

    // Reverse the linked list
    Node* prev = nullptr;
    Node* current = Head;
    Node* Next = nullptr;

    while(current != nullptr) {
        Next = current->Next;   // Store next node
        current->Next = prev;   // Reverse the link
        prev = current;         // Move prev forward
        current = Next;         // Move current forward
    }
    Head = prev;  // Update head to new first node

    // Display reversed list
    cout << endl << "This is the linked list after reversal" << endl;
    temp = Head;
    while (temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }
    cout << endl;

    // Free allocated memory
    while(Head != nullptr)
    {
        Node* Del = Head;
        Head = Head->Next;
        delete Del;
    }
    Head = nullptr;

    return 0;
}