#include <iostream>
#include <queue>  // Include STL queue library
using namespace std;

int main()
{
    // Create a queue of integers using STL
    queue<int> MyQueue;

    // Check if queue is empty
    cout << "Is empty? " << MyQueue.empty() << endl;  // 1 = true

    // Push elements to the back of the queue
    MyQueue.push(6);
    MyQueue.push(62);
    MyQueue.push(23);
    MyQueue.push(615);
    MyQueue.push(69);
    cout << "Pushed 5 elements" << endl;

    // Display queue size
    cout << "Size: " << MyQueue.size() << endl;  // 5

    // View front and back elements without removing
    cout << "Front: " << MyQueue.front() << endl;  // 6 (first element)
    cout << "Back: " << MyQueue.back() << endl;    // 69 (last element)

    // Remove element from the front (FIFO)
    MyQueue.pop();
    cout << "After pop:" << endl;
    cout << "Front: " << MyQueue.front() << endl;  // 62 (new front)
    cout << "Back: " << MyQueue.back() << endl;    // 69 (unchanged)

    // Add another element to the back
    MyQueue.push(6110);
    cout << "After push:" << endl;
    cout << "Front: " << MyQueue.front() << endl;  // 62
    cout << "Back: " << MyQueue.back() << endl;    // 6110 (new back)

    // Display current size
    cout << "Size: " << MyQueue.size() << endl;    // 5 (62,23,615,69,6110)

    // Check if queue is empty
    cout << "Is empty? " << MyQueue.empty() << endl;  // 0 = false

    // emplace() constructs element in-place (similar to push)
    MyQueue.emplace(5);
    cout << "Back after emplace: " << MyQueue.back() << endl;  // 5

    // Create another queue
    queue<int> YourQueue;
    YourQueue.push(9);
    YourQueue.push(8);

    // Swap contents of two queues
    MyQueue.swap(YourQueue);

    cout << "After swap:" << endl;
    cout << "MyQueue front: " << MyQueue.front() << endl;    // 9
    cout << "MyQueue back: " << MyQueue.back() << endl;      // 8
    cout << "YourQueue front: " << YourQueue.front() << endl; // 62
    cout << "YourQueue back: " << YourQueue.back() << endl;   // 5

    return 0;
}