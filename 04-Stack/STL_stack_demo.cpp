#include <iostream>
#include <stack>  // Include stack library (STL)
using namespace std;

int main()
{
    // Create a stack of integers using STL
    stack<int> MyStack;

    // Check if stack is empty
    cout << "Is empty? " << MyStack.empty() << endl; // 1 = true (empty)

    // Push elements onto the stack (add to top)
    MyStack.push(6);
    MyStack.push(62);
    MyStack.push(23);
    MyStack.push(615);
    MyStack.push(69);
    cout << "Pushed 5 elements" << endl;

    // Display stack size and top element
    cout << "Size: "  << MyStack.size()  << endl; // 5
    cout << "Top: "   << MyStack.top()   << endl; // 69 (last element pushed)

    // Remove top element (LIFO)
    MyStack.pop();
    cout << "Popped top element" << endl;

    // Check stack after pop
    cout << "Top after pop: " << MyStack.top()   << endl; // 615
    cout << "Size after pop: " << MyStack.size() << endl; // 4
    cout << "Is empty? " << MyStack.empty() << endl; // 0 = false (not empty)

    // emplace() constructs element in-place (similar to push)
    MyStack.emplace(5);
    cout << "After emplace, Top: " << MyStack.top() << endl; // 5

    // Create another stack
    stack<int> YourStack;
    YourStack.push(9);
    YourStack.push(8);

    // Swap contents of two stacks
    MyStack.swap(YourStack);
    cout << "After swap:" << endl;
    cout << "MyStack top: "   << MyStack.top()   << endl; // 8
    cout << "YourStack top: " << YourStack.top() << endl; // 5

    return 0;
}