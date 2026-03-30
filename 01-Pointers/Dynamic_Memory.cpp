#include <iostream>
using namespace std;

int main() {
    // Creating dynamic pointer for int = 5
    int* p = new int(5);

    // Print value using the pointer
    cout << *p << endl;

    // Delete the pointer to prevent memory leak
    delete p;
    // Initialize pointer by assigning it to nullptr to prevent dangling pointer
    p = nullptr;

    return 0;
}