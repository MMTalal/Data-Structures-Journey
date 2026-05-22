#include<iostream>
#include<vector>
using namespace std;

int size;           // Maximum capacity of the queue
int front = -1;     // Points to the front element (where we dequeue from)
int rear = -1;      // Points to the rear element (where we enqueue to)
vector<int> arr;    // Dynamic array to store queue elements

// Add an element to the rear of the queue
void Enqueue(int value)
{
    // Check if queue is full
    if(rear == size - 1)
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        // Case 1: Queue is empty
        if(front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = value;
        }
        // Case 2: Queue has elements
        else
        {
            rear++;
            arr[rear] = value;
        }
    }
}

// Remove an element from the front of the queue
void Dequeue()
{
    // Check if queue is empty
    if((front == -1 && rear == -1) || front > rear)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        // Case 1: Only one element left
        if(front == rear)
        {
            front = rear = -1;  // Reset queue to empty
        }
        // Case 2: Multiple elements
        else
        {
            front++;  // Move front pointer forward
        }
    }
}

// Display all elements in the queue (from front to rear)
void Display()
{
    // Check if queue is empty
    if((front == -1 && rear == -1) || front > rear)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        for(int i = front; i < rear + 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// View the front element without removing it
void Peek()
{
    // Check if queue is empty
    if((front == -1 && rear == -1) || front > rear)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Front element is: " << arr[front] << endl;
    }
}

// Remove all elements from the queue
void Clean()
{
    // Check if queue is empty
    if((front == -1 && rear == -1) || front > rear)
    {
        cout << "Queue is already empty!" << endl;
    }
    else
    {
        front = rear = -1;  // Reset pointers
        cout << "Queue cleaned successfully!" << endl;
    }
}

// Search for a specific value in the queue
void Search(int value)
{
    bool found = false;

    // Check if queue is empty
    if((front == -1 && rear == -1) || front > rear)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        // Linear search through the queue
        for(int i = front; i < rear + 1; i++)
        {
            if(arr[i] == value)
            {
                found = true;
                break;
            }
        }
        
        if(found == true)
        {
            cout << "Value " << value << " is found in the queue!" << endl;
        }
        else
        {
            cout << "Value " << value << " is NOT found in the queue!" << endl;
        }
    }
}

int main()
{
    cout << "Let's build a queue together using an array" << endl;
    cout << "What is your queue size?" << endl;

    cin >> size;

    // Validate queue size
    if(size <= 0)
    {
        cout << "Queue size cannot be less than or equal to zero!" << endl;
        return -1;
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