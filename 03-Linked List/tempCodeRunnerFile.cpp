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

    // Step 4: User input for insertion position
    cout << "You can delete a value at any position in the linked list" << endl;
    cout << "Enter position to delete his value : " << endl;

    int position;
    cin >> position;

    // Step 5: Delete at beginning
    if(position == 1)
    {
        Node* NewHead = Head;
        Head = Head->Next;
        delete NewHead;
    }

    // Step 6: Delete in middle or end
    else if(position > 1)
    {
       
        if(count > position)
        {
             // Traverse to node just before the insertion point
            Node* temp = Head;
            int i = 1;

            while( i < position - 1)
            {
                temp = temp->Next;
                i++;
            }
            if(temp != nullptr || temp->Next = nullptr)
            {
                // Rewire pointers to delete node
                Node* toDelete = temp->Next;
                temp->Next = toDelete->Next;
                delete toDelete;
            }
        }
        else
        {

        }
    }

    // Step 7: Handle invalid position
    else
    {
        cout << "Invalid position entered!" << endl;
        return 1;
    }

    // Step 8: Display updated list
    int newCount = 0;
    Node* current = Head;

    while(current != nullptr)
    {
        cout << current->Data << " ";
        current = current->Next;
        newCount++;
    }

    cout << endl;
    cout << "Linked list size decreased from " << count
         << " to " << newCount << " elements" << endl;

    // Step 9: Free allocated memory
    while(Head != nullptr)
    {
        Node* del = Head;
        Head = Head->Next;
        delete del;
    }

    Head = nullptr; // Avoid dangling pointer

    return 0;
}