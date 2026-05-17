#include <iostream>
using namespace std;

#define size 5  // Define maximum size of the stack

int stack[size];  // Array to store stack elements
int top = -1;     // Initialize top pointer (-1 means empty stack)

// Push element onto the stack
void push(int value)
{
    if(top == size - 1)  // Check if stack is full
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;               // Move top up
        stack[top] = value;  // Add value to stack
    }
}

// Pop element from the stack
int pop()
{
    if(top == -1)  // Check if stack is empty
    {
        cout << "Stack Underflow!" << endl;
        return -1;  // Return -1 to indicate error
    }
    else
    {
        return stack[top--];  // Return top value and decrement top
    }
}

// Peek at top element without removing it
int peek()
{
    if(top == -1)  // Check if stack is empty
    {
        cout << "Stack Underflow!" << endl;
        return -1;  // Return -1 to indicate error
    }
    else
    {
        return stack[top];  // Return top value without removing
    }
}

// Display all stack elements
void display()
{
    if(top == -1)
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        cout << endl << "Stack elements are:" << endl;
        for(int i = top; i >= 0; i--)  // Print from top to bottom
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    push(5);
    push(10);
    push(15);
    display();
    cout << endl << "Peek: " << peek();
    cout << endl << "Popped: " << pop();
    display();
    cout << endl << "Peek: " << peek();
    
    return 0;
}