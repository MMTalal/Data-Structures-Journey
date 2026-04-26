#include <iostream>
using namespace std;

struct Node {
    int Data;
    Node* Next;
};

Node* Head = nullptr;

// Insert new node at the end of the list
void insert(int Data)
{
    Node* NewNode = new Node();
    NewNode->Data = Data;

    if(Head == nullptr)
    {
        // List is empty, this becomes the first node
        cout << "Your linked list is empty" << endl;
        NewNode->Next = nullptr;
        Head = NewNode;
    }
    else
    {
        // Traverse to the last node
        Node* temp = Head;
        while(temp->Next != nullptr)
            temp = temp->Next;
        temp->Next = NewNode;
        NewNode->Next = nullptr;
    }
}

// Display all elements in the list
void display(Node* Head)
{
    Node* temp = Head;
    while(temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->Next;
    }
    cout << endl;
}

// Delete the last node (End) of the list
void DeleteEnd()
{
    if(Head == nullptr)
    {
        cout << "Linked list is already empty!" << endl;
    }
    else if(Head->Next == nullptr)
    {
        // Only one node in the list
        delete Head;
        Head = nullptr;
        cout << "Last node deleted successfully!" << endl;
    }
    else
    {
        // Traverse to find the second-to-last node
        Node* current = Head;
        
        // Stop at the node before the last node
        while(current->Next->Next != nullptr)
        {
            current = current->Next;
        }
        
        // Delete the last node
        delete current->Next;
        current->Next = nullptr;
        
        cout << "Last node deleted successfully!" << endl;
    }
}

// Delete all nodes (clean entire list)
void clean()
{
    if(Head == nullptr)
    {
        cout << "Linked list is already empty!" << endl;
    }
    else
    {
        while(Head != nullptr)
        {
            Node* clean = Head;
            Head = Head->Next;
            delete clean;
        }
        cout << "Entire list cleaned!" << endl;
    }
}

int main() {
    cout << "Let's build your linked list" << endl;
    cout << "What is the size of your linked list?" << endl;

    int size;
    cin >> size;
    
    if(size < 0)
    {
        cout << "Size cannot be less than zero!" << endl;
        return 1;
    }
    else if(size == 0)
    {
        cout << "You created a node but it's empty" << endl;
        Node* NewNode = new Node();
        Head = NewNode;
        NewNode->Next = nullptr;
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            cout << "What is the value of element No. " << i + 1 << endl;
            int value;
            cin >> value;
            insert(value);
        }
    }

    cout << "Your linked list values are:" << endl;
    display(Head);

    cout << "Do you want to remove the last element from your linked list? (y/n)" << endl;
    string remove;
    cin >> remove;

    if (remove == "n" || remove == "N" || remove == "no" || remove == "No")
    {
        cout << "OK.. your linked list still has no changes" << endl;
        display(Head);
    }
    else if(remove == "y" || remove == "Y" || remove == "yes" || remove == "Yes")
    {
        DeleteEnd();  // Delete last node
        cout << "OK.. your linked list after changes is:" << endl;
        display(Head);
    }
    else
    {
        cout << "Invalid input!" << endl;
        return 1;
    }

    return 0;
}