#include<iostream>
using namespace std;

// Node structure for Queue (FIFO data structure)
struct Node{
    int Data;      // Value stored in the node
    Node* Next;    // Pointer to the next node
};

// Queue pointers
Node* First = nullptr;  // Points to the front of the queue (where we remove)
Node* Last  = nullptr;  // Points to the rear of the queue (where we add)

// Check if the queue is empty and print status
void IsEmpty()
{
    if(First == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue isn't empty" << endl;
    }
}

// Display all elements in the queue (from front to rear)
void Display()
{
    if(First == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node* temp = First;
        while(temp != nullptr)
        {
            cout << temp->Data << " ";
            temp = temp->Next;
        }
    }
    cout << endl;
}

// Add an element to the rear of the queue (FIFO)
void Enqueue(int value)
{
    Node* NewNode = new Node();
    NewNode->Data = value;
    NewNode->Next = nullptr;
    
    // Case 1: Queue is empty
    if(First == nullptr)
    {
        First = NewNode;
        Last  = NewNode;
    }
    // Case 2: Queue has elements
    else
    {
        Last->Next = NewNode;  // Link current last to new node
        Last = Last->Next;      // Update last pointer
    }
}

// Count the number of elements in the queue
void Count()
{
    int count = 0;
    
    if(First == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else
    {
        Node* temp = First;
        while(temp != nullptr)
        {
            count++;
            temp = temp->Next;
        }
    }
    cout << "Count of queue is: " << count << endl;
}

// Remove an element from the front of the queue (FIFO)
void Dequeue()
{
    // Case 1: Queue is empty
    if(First == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    // Case 2: Only one element in the queue
    else if(First == Last)
    {
        Node* temp = First;
        delete temp;
        First = Last = nullptr;
    }
    // Case 3: Multiple elements in the queue
    else
    {
        Node* temp = First;
        First = First->Next;  // Move first pointer to next node
        delete temp;          // Delete old first node
        
        // If queue becomes empty, update last pointer
        if(First == nullptr)
        {
            Last = nullptr;
        }
    }
}

// Delete all elements from the queue
void Clean()
{
    if(First == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        while(First != nullptr)
        {
            Dequeue();  // Remove front element repeatedly
        }
        cout << "Queue is cleaned successfully" << endl;
    }
}

// Search for a specific value in the queue
void IsFound(int value)
{
    bool found = false;

    Node* temp = First;
    while(temp != nullptr)
    {
        if(temp->Data == value)
        {
            found = true;
            break;
        }
        temp = temp->Next;
    }
    
    if(found == true)
    {
        cout << "Your value is found in queue" << endl;
    }
    else
    {
        cout << "Your value isn't found in queue" << endl;
    }
}

// View the front element without removing it
void Peek()
{
    if(First == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Peek of Queue: " << First->Data << endl;
    }
}

int main(){
    // Test queue operations
    IsEmpty();          // Check if queue is empty
    
    // Add elements to queue
    Enqueue(5);
    Enqueue(10);
    Enqueue(75);
    Enqueue(52);
    Enqueue(154);
    
    Display();          // Show all elements
    
    Dequeue();          // Remove front element (5)
    Peek();             // View new front (10)
    
    Dequeue();          // Remove front element (10)
    
    // Add more elements
    Enqueue(147);
    Enqueue(171);
    
    Peek();             // View front (75)
    IsEmpty();          // Check if queue is empty
    Display();          // Show all elements
    Count();            // Count elements
    
    Dequeue();          // Remove front (75)
    Display();          // Show remaining elements
    
    Clean();            // Delete all elements
    IsFound(5);         // Search for value (not found)
    Peek();             // Try to peek empty queue

    return 0;
}