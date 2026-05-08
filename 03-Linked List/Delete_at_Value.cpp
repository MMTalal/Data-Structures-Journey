#include <iostream>
using namespace std;

// Node structure representing a single element in the linked list
struct Node {
    int Data;       // Value stored in the node
    Node* Next;     // Pointer to the next node in the list
};

// Head pointer pointing to the first node of the linked list
Node* Head = nullptr;

int main() {

    // Step 1: Create nodes manually
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();
    Node* d = new Node();
    Node* e = new Node();

    // Step 2: Assign values and link nodes
    a->Data = 1;
    a->Next = b;

    b->Data = 2;
    b->Next = c;

    c->Data = 3;
    c->Next = d;

    d->Data = 4;
    d->Next = e;

    e->Data = 5;
    e->Next = nullptr; // Last node points to NULL

    // Set head pointer to the first node
    Head = a;

    cout << "This is a linked list of 5 elements" << endl;

    // Step 3: Display original list and count nodes
    int count = 0;
    Node* temp = Head;

    while(temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
        count++;
    }

    cout << endl;

    // Step 4: User input for value to delete
    cout << "You can delete any value in the linked list" << endl;
    cout << "Enter value you want to delete: " << endl;

    int value;
    cin >> value;

    bool found = false;

    // Special case: delete head node
    if(Head->Data == value)
    {
        Node* toDelete = Head;
        Head = Head->Next;
        delete toDelete;
        found = true;
    }
    else
    {
        // Search for the value in the list
        Node* previous = Head;
        Node* current = Head->Next;

        while(current != nullptr)
        {
            if(current->Data == value)
            {
                // Delete current node
                previous->Next = current->Next;
                delete current;
                found = true;
                break;
            }
            previous = current;
            current = current->Next;
        }
    }

    // Display result
    if(found == true)
    {
        cout << "Value deleted successfully!" << endl;
    }
    else
    {
        cout << "Value not found in the linked list!" << endl;
        return 1;
    }

    // Display updated list
    int newCount = 0;
    Node* current = Head;

    while(current != nullptr)
    {
        cout << current->Data << " ";
        current = current->Next;
        newCount++;
    }

    cout << endl;
    cout << "Linked list size decreased from " << count << " to " << newCount << " elements" << endl;

    // Free allocated memory
    while(Head != nullptr)
    {
        Node* del = Head;
        Head = Head->Next;
        delete del;
    }

    Head = nullptr; // Avoid dangling pointer

    return 0;
}