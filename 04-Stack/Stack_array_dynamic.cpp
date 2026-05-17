#include <iostream>
using namespace std;

int top = -1;  // Global top pointer for the stack

// Push element onto the stack
void push(int stack[], int size, int value)
{
    if(top == size - 1)  // Check if stack is full
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

// Pop element from the stack
int pop(int stack[])
{
    if(top == -1)  // Check if stack is empty
    {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    else
    {
        return stack[top--];  // Return top value and decrement top
    }
}

// Peek at top element without removing it
int peek(int stack[])
{
    if(top == -1)
    {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    else
    {
        return stack[top];
    }
}

// Display all stack elements
void display(int stack[])
{
    if(top == -1)
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << endl << "Stack elements are:" << endl;
        for(int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Let's build a stack together using array" << endl;
    cout << "What is the size of your stack?" << endl;
    int size;
    cin >> size;
    
    if(size <= 0)
    {
        cout << "Size cannot be less than or equal to zero!" << endl;
        return 1;  
    }
    
    // Create dynamic array on heap
    int* stack = new int[size];

    // Push elements into stack
    for(int i = 0; i < size; i++)
    {
        cout << "Enter value for element No. " << i + 1 << ": ";
        int value;
        cin >> value;
        push(stack, size, value);
    }

    // Display results
    display(stack);
    cout << endl << "Peek: " << peek(stack);
    cout << endl << "Popped: " << pop(stack);
    display(stack);
    cout << endl << "Peek: " << peek(stack);
    cout << endl << "Count: " << top + 1 << endl;
    
    // Free allocated memory (important!)
    delete[] stack;
    stack = nullptr;
    
    return 0;
}