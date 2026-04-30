#include <iostream>
using namespace std;

// Node structure definition, each node contains:
struct Node {
    int Data;    // - Data (value)
    Node* Next;  // - Next pointer to next node
};

// Head pointer (start of linked list)
Node* Head = nullptr;

int main() {

    // Step 1: Create 5 nodes manually
    Node* a = new Node();
    Node* b = new Node();
    Node* c = new Node();
    Node* d = new Node();
    Node* e = new Node();

    // Step 2: Link nodes together
    a->Data = 1;
    a->Next = b;

    b->Data = 2;
    b->Next = c;

    c->Data = 3;
    c->Next = d;

    d->Data = 4;
    d->Next = e;

    e->Data = 5;
    e->Next = nullptr; // last node points to NULL

    // Assign head to first node
    Head = a;

    cout << "This is a linked list of 5 elements" << endl;

    // Step 3: Traverse list + count nodes
    int count = 0;
    Node* temp = Head;

    while(temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
        count++;
    }

    // Step 4: Get user input (target + value)
    cout << endl << "You can insert a new value before any target value in this linked list" << endl;
    cout << "Enter target value (insert BEFORE it):" << endl;
    int targetValue;
    cin >> targetValue;

    bool f = false;

    Node* found = Head;

    while(found->Next != nullptr)
    {
        if(found->Next->Data == targetValue)
        {
            f = true;
            break;
        }
        found = found->Next;
    }

    if(f == true || Head->Data == targetValue)
    {
        cout << "Enter new value: ";
        int value;
        cin >> value;

        Node* newNode = new Node();
        newNode->Data = value;

        if(Head->Data == targetValue)
        {
            newNode->Next = Head;
            Head = newNode;
        }
        else
        {
            newNode->Next = found->Next;
            found->Next = newNode;
        }
    }
    else
    {
        cout << "your target value is not found" << endl;
        return 1;
    }

    // Step 9: Print updated list
    int newCount = 0;
    Node* current = Head;

    while(current != nullptr)
    {
        cout << current->Data << " ";
        current = current->Next;
        newCount++;
    }

    cout << endl;
    cout << "Linked list increased from " << count << " to " << newCount << " elements" << endl;

    // Step 10: Free memory (important)
    Node* del = Head;

    while(del != nullptr)
    {
        Node* nextNode = del->Next; // save next node
        delete del;                 // delete current node
        del = nextNode;             // move forward
    }

    Head = nullptr; // avoid dangling pointer

    return 0;
}