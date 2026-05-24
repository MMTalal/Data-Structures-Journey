#include<iostream>
#include<vector>
using namespace std;

int size;           // Maximum capacity of the queue
int front = -1;     // Points to the front element (where we dequeue from)
int rear = -1;      // Points to the rear element (where we enqueue to)
vector<int> arr;    // Dynamic array to store queue elements

// Check if the queue is empty
bool IsEmpty()
{
    return (front == -1 && rear == -1);
}

// Check if the queue is full (Circular logic)
bool IsFull()
{
    return (rear + 1) % size == front;
}

// Add an element to the rear of the queue (Circular)
void Enqueue(int value)
{
    // Check if queue is full
    if(IsFull())
    {
        cout << "Circle queue is full!" << endl;
        return;
    }
    
    // Case 1: Queue is empty
    if(IsEmpty())
    {
        front = 0;
        rear = 0;
        arr[rear] = value;
    }
    // Case 2: Wrap around to beginning (circular)
    else if(rear == size - 1)
    {
        rear = 0;
        arr[rear] = value;
    }
    // Case 3: Normal case
    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Remove an element from the front of the queue (Circular)
void Dequeue()
{
    // Check if queue is empty
    if(IsEmpty())
    {
        cout << "Circle queue is empty!" << endl;
        return;
    }
    
    // Case 1: Only one element left
    if(front == rear)
    {
        front = rear = -1;  // Reset queue to empty
    }
    // Case 2: Wrap around to beginning (circular)
    else if(front == size - 1)
    {
        front = 0;
    }
    // Case 3: Normal case
    else
    {
        front++;  // Move front pointer forward
    }
}

// Display all elements in the queue (from front to rear)
void Display()
{
    if(IsEmpty())
    {
        cout << "Circle queue is empty!" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = front;

    // Traverse from front to rear using modulo arithmetic
    while(i != rear)
    {
        cout << arr[i] << " ";
        i = (i + 1) % size;
    }

    // Print the last element (rear)
    cout << arr[rear] << endl;
}

// View the front element without removing it
void Peek()
{
    if(IsEmpty())
    {
        cout << "Circle queue is empty!" << endl;
        return;
    }
    
    cout << "Front element is: " << arr[front] << endl;
}

// Remove all elements from the queue
void Clean()
{
    if(IsEmpty())
    {
        cout << "Circle queue is already empty!" << endl;
        return;
    }
    
    front = rear = -1;  // Reset pointers
    cout << "Queue cleaned successfully!" << endl;
}

// Search for a specific value in the queue
void Search(int value)
{
    if(IsEmpty())
    {
        cout << "Circle queue is empty!" << endl;
        return;
    }

    int i = front;
    bool found = false;

    // Traverse from front to rear
    while(i != rear)
    {
        if(arr[i] == value)
        {
            found = true;
            break;
        }
        i = (i + 1) % size;
    }

    // Check the last element (rear)
    if(arr[rear] == value)
    {
        found = true;
    }

    if(found)
    {
        cout << "Value " << value << " found in the queue!" << endl;
    }
    else
    {
        cout << "Value " << value << " NOT found in the queue!" << endl;
    }
}

int main()
{
    cout << "Let's build a circular queue together using an array" << endl;
    cout << "What is your queue size?" << endl;

    cin >> size;

    // Validate queue size
    if(size <= 0)
    {
        cout << "Queue size cannot be less than or equal to zero!" << endl;
        return 0;
    }
    
    // Resize vector to hold queue elements
    arr.resize(size);

    // Get user input and fill the queue
    for(int i = 0; i < size; i++)
    {
        cout << "What is the value of element number " << i + 1 << "?" << endl;
        int num;
        cin >> num;
        Enqueue(num);   
    }

    Display();
    Dequeue();
    Search(20);
    Display();
    Peek();
    Clean();
    Display();
    Peek();


    return 0;    
}