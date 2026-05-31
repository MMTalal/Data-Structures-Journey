# 🗺️ Data Structures Journey — Mahmoud's Learning Path

> From GIS Analyst → GIS Developer | Learning Data Structures with C++

---

## 👤 About This Repo

This repository documents my personal journey learning **Data Structures and Algorithms** using **C++**, as part of my path toward becoming a **GIS Developer / Geospatial Engineer**.

Every file here is a hands-on exercise — not just theory.

---

## 📁 Repo Structure

```
data-structures-journey/
│
├── 01-pointers/
│   ├── Pointer_basics.cpp
│   ├── Dynamic_Memory.cpp
│   ├── Dynamic_array.cpp
│   ├── Increment_pointer.cpp
│   ├── Swap_using_pointers.cpp
│   ├── Pointer_swap_Function.cpp
│   ├── Pointer_swap_Function_ByReference.cpp
│   ├── Add_ten_function.cpp
│   ├── Dynamic_array_input.cpp
│   └── Dynamic_array_input_sum.cpp
│
├── 02-arrays/
│   ├── Array_reverse_output.cpp
│   ├── Array_sum_with_dynamic_size_and_length.cpp
│   ├── Smallest_element.cpp
│   ├── Array_search.cpp
│   ├── Count_even_numbers.cpp
│   ├── Two_pointer_reverse_in-place.cpp
│   ├── Array_cleanup_sorted.cpp
│   ├── Array_merge.cpp
│   ├── Find_array_range.cpp
│   ├── Pair_sum_search.cpp
│   ├── Array_Rotation.cpp
│   ├── Kadane's_algorithm.cpp
│   └── Vector_operations.cpp
│
├── 03-linked-lists/
│   ├── Traversal.cpp
│   ├── Extract_length_and_maximum_value.cpp
│   ├── Recursive_reverse_print.cpp
│   ├── Insert_at_front.cpp
│   ├── Insert_at_end.cpp
│   ├── Search.cpp
│   ├── Delete_at_front.cpp
│   ├── Delete_at_end.cpp
│   ├── Insert_before_position.cpp
│   ├── Insert_before_Value.cpp
│   ├── Delete_at_Position.cpp
│   ├── Delete_at_value.cpp
│   ├── Reverse_linked_list.cpp
│   └── Music_playlist_circular.cpp
│
├── 04-stacks/  
│   ├── Stack_linked_list.cpp
│   ├── STL_stack_demo.cpp
│   ├── Stack_array_static.cpp
│   └── Stack_array_dynamic.cpp
│
├── 05-queues/
│   ├── Queue_linked_list.cpp
│   ├── Queue_array.cpp
│   ├── Circular_queue_array.cpp
│   └── STL_queue_demo.cpp
│
├── 06-trees/
│   └── Binary_search_tree.cpp
│   
└── 07-graphs/    🔜 Coming soon
```

---

## ✅ Progress

| Topic | Status | Files |
|-------|--------|-------|
| Pointers & Memory Mangement | ✅ Done | 10 files |
| Arrays & Dynamic Arrays | ✅ Done | 13 files |
| Linked Lists | ✅ Done | 14 files |
| Stack | ✅ Done | 04 files |
| Queue | ✅ Done | 04 files |
| Trees  | ✅ Done | 01 file |
| Graphs | ⏳ Planned | — |

---

# 📦 Part 1 — Linear Data Structures
 
> Structures where elements are arranged sequentially, one after another.
> Each element has a unique predecessor and successor (except at boundaries).
 
---

## 📌 01 — Pointers & Dynamic Memory

### Concepts Covered

- Difference between **Stack** and **Heap** memory
- Creating and using **pointers** (`int* p`)
- **Dereferencing** a pointer (`*p`)
- **Dynamic memory allocation** (`new` / `delete`)
- Preventing **Memory Leak** and **Dangling Pointer**
- Passing pointers to functions (**Pass by Address**)
- Passing by **Reference** vs passing by **Pointer**
- Swapping values using pointers

### Key Rules Learned

```cpp
int* p = new int(5);   // Allocate on Heap
*p = 10;               // Modify value via pointer
delete p;              // Free memory → prevent Memory Leak
p = nullptr;           // Reset pointer → prevent Dangling Pointer
```

```cpp
// Arrays on Heap
int* arr = new int[5];
delete[] arr;          // Note: delete[] not delete
arr = nullptr;
```

### Files

| File | What it does |
|------|-------------|
| `Pointer_basics.cpp` | Basic pointer creation, dereferencing, and value modification |
| `Dynamic_Memory.cpp` | Allocating a single integer on the Heap and freeing it safely |
| `Dynamic_array.cpp` | Allocating an array on the Heap, filling it 1–5, and freeing it |
| `Increment_pointer.cpp` | Function that takes a pointer and increments its value by 1 |
| `Swap_using_pointers.cpp` | Swapping two variable values using pointers directly in main |
| `Pointer_swap_Function.cpp` | Swap function using pointers (Pass by Address) |
| `Pointer_swap_Function_ByReference.cpp` | Swap function using references (Pass by Reference) |
| `Add_ten_function.cpp` | Function that takes an integer and adds 10 to it |
| `Dynamic_array_input.cpp` | Creates a dynamic array of 3 integers on the heap from user and print it |
| `Dynamic_array_input_sum.cpp` | Creates a dynamic array of (N) integers on the heap, and calculates the sum |

---

### 🧠 Key Concepts Summary

#### Memory Layout

```
Stack                        Heap
|--------------|            |--------------|
| int x = 5   |            |     [10]     | ← new int(10)
| int* p  ----+----------> |   address    |
|--------------|            |--------------|

Stack → fixed size, auto-managed, fast
Heap  → dynamic size, manual (new/delete), flexible
```

#### Pointer Cheat Sheet

```cpp
int  x  = 5;      // regular variable (Stack)
int* p  = &x;     // pointer holds address of x
     *p = 10;     // dereference: change x via pointer → x is now 10
```

#### Pass by Pointer vs Pass by Reference

```cpp
// Pass by Pointer — caller must use &
void increment(int* p) { (*p)++; }
increment(&x);

// Pass by Reference — cleaner, no & needed at call site
void increment(int& r) { r++; }
increment(x);
```

#### Dynamic Memory Rules

```cpp
// Single value
int* p = new int(5);   // allocate
delete p;              // free
p = nullptr;           // prevent dangling pointer

// Array
int* arr = new int[n]; // allocate array
delete[] arr;          // MUST use delete[] not delete
arr = nullptr;
```

#### Common Mistakes to Avoid

| Mistake | Problem | Fix |
|---------|---------|-----|
| Forget `delete` after `new` | Memory Leak | Always pair `new` with `delete` |
| Forget `nullptr` after `delete` | Dangling Pointer | Always set pointer to `nullptr` |
| Use `delete` on array | Undefined behavior | Use `delete[]` for arrays |
| Reassign pointer without `delete` | Memory Leak | `delete` first, then reassign |
| Dereference `nullptr` | Crash | Always check pointer before use |
| Return address of local variable | Dangling Pointer | Only return Heap addresses |

---


## 📌 02 — Arrays

### Concepts Covered

- Array as **contiguous memory** on the Stack
- **Static** vs **Dynamic** arrays
- Array name as a **Pointer** to the first element
- Accessing elements via **Index** and via **Pointer arithmetic**
- Relationship: `arr[i]` == `*(arr + i)`
- Traversal using **For Loop** (forward and backward)
- Address calculation: `Base Address + (Index × sizeof(type))`
- Traversal using **For Loop** — forward (`i = 0` to `size-1`) and backward (`i = size-1` to `0`)
- **Loop boundaries** — why `i < size` not `i <= size` (avoid Out-of-Bounds)
- Creating **dynamic arrays** with user-defined size at runtime (`new int[n]`)
- **Boundary validation** — checking `length > size` before filling
- **Accumulator pattern** — `sum = sum + arr[i]` inside a loop
- Always `delete[]` + `nullptr` after dynamic arrays to prevent **Memory Leak**


### Key Rules Learned

```cpp
// Array name IS a pointer to first element
int arr[5] = {10, 20, 30, 40, 50};
cout << arr;       // prints address of arr[0]
cout << *arr;      // prints 10 (same as arr[0])
cout << *(arr+2);  // prints 30 (same as arr[2])

// Loop backward
for (int i = 4; i >= 0; i--) {
    cout << arr[i];
}
```
### Vector — The Modern Way
 
`vector` is a dynamic array from the C++ Standard Library that handles memory automatically (no `new` / `delete` needed).
 
```cpp
#include <vector>  // ← must include this header
```
 
**Creating a vector:**
 
```cpp
vector<int> arr(5);          // vector of 5 integers (initialized to 0)
vector<int> arr(5, 99);      // vector of 5 integers (all = 99)
vector<int> arr = {1,2,3};   // vector initialized with values
```
 
**Accessing elements — same as array:**
 
```cpp
arr[0] = 10;        // write
cout << arr[0];     // read
```
 
**Useful vector operations:**
 
```cpp
arr.size();         // returns number of elements
arr.push_back(99);  // adds element at the end
arr.pop_back();     // removes last element
arr.data();         // returns raw pointer (used when passing to pointer functions)
```
 
**Looping through a vector:**
 
```cpp
// Classic loop
for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
}
 
// Range-based loop
for (int x : arr) {
    cout << x << " ";
}
```
 
**Vector vs Raw Pointer:**
 
| | Raw Pointer (`int*`) | Vector |
|---|---|---|
| **Memory** | Manual (`new` / `delete`) | Automatic |
| **Memory Leak risk** | Yes | No |
| **Flexibility** | Full control | Easier to use |
| **Use when** | Learning internals / Linked List / Tree | General programs |
 
> **Key insight:** `vector` does the same thing as `new int[n]` internally — but hides the details. Understanding pointers first makes vector easy to understand. 🧠


### Files

| File | What it does |
|------|-------------|
| `Array_reverse_output.cpp` | Takes 5 integers from user and prints them in reverse order |
| `Array_sum_with_dynamic_size_and_length.cpp` | Creates a dynamic array with user-defined size, asks user how many elements to fill (length), validates that length does not exceed size, fills the array with user input, prints all entered elements, and calculates their sum |
| `Smallest_element.cpp` | Takes (N) integers from user and Finds the smallest (minimum) value |
| `Array_search.cpp` | Creates a dynamic array with user-defined size, validates size and length, fills the array with user input, searches for a user-defined target using Linear Search with foundIndex pattern, prints the index if "found" or "not found" if not |
| `Count_even_numbers.cpp` | Takes (N) integers from user and Finds the count of even numbers |
| `Two_pointers_reverse_in-place.cpp` | Reverse dynamic array of (N) integers in-place using two pointers on the heap |
| `Array_cleanup_sorted.cpp` | takes (N) integers from user and cleanup duplicates (This logic requires array to be sorted) |
| `Array_merge.cpp` | Merge two sorted arrays with ascending order validation |
| `Find_array_range.cpp` | Find Max & Min number and calculates the difference between them |
| `Pair_sum_search.cpp` | Searches for two different elements that sum to the target |
| `Array_Rotation.cpp` | Creates a dynamic array Using Vector with user-defined size and length, takes a rotation value k from user, validates all inputs, then rotates the array right by k steps using the triple reverse technique (reverse all → reverse first k → reverse remaining), and prints the rotated result |
| `Kadane's_algorithm.cpp` | Finds the maximum sum of any contiguous subarray using Kadane's Algorithm |
| `Vector_operations.cpp` | Creates a vector, lets the user add elements, view them, retrieve/modify specific elements, and optionally resize the vector through an interactive menu |

---

## 🧠 Key Concepts Summary

### Memory Layout

```
Stack                    Heap
|----------|            |----------|
| int x=5  |            |   [10]   | ← new int(10)
| int* p --|----------> | address  |
|----------|            |----------|
```

### Array in Memory

```
arr[0]  arr[1]  arr[2]  arr[3]  arr[4]
  10      20      30      40      50
 1000    1004    1008    1012    1016   ← addresses (int = 4 bytes)
  ↑
arr (pointer to first element)
```

### Common Mistakes to Avoid

| Mistake | Problem | Fix |
|---------|---------|-----|
| Forget `delete` | Memory Leak | Always `delete` after `new` |
| Forget `nullptr` after `delete` | Dangling Pointer | Always set `p = nullptr` |
| Use `delete` instead of `delete[]` for arrays | Undefined behavior | Use `delete[]` for arrays |
| Reassign pointer without `delete` | Memory Leak | `delete` first, then reassign |
| `i <= size` in loop | Out-of-bounds access | Always use `i < size` |
| `arr[size]` access | Undefined behavior | Last valid index is `size - 1` |
| Initialize with `arr[0]` then loop from `i = 0` | Counts `arr[0]` twice | If you initialize a variable with `arr[0]`, always start the loop from `i = 1` |


---

## 📌 03 — Linked Lists
 
### Why Linked Lists?
 
Arrays store elements in **contiguous memory** — inserting or deleting at the beginning requires shifting every element. A **Linked List** solves this: each node holds a value and a pointer to the next node, so insertion and deletion at the front cost **O(1)** regardless of size.
 
```
Array:       [10][20][30][40]   ← contiguous, insert at front = shift all
Linked List: [10]→[20]→[30]→[40]→NULL  ← insert at front = rewire one pointer
```
 
### Concepts Covered
 
- **Node** structure: `data` field + `next` pointer (the building block of every Linked List)
- **Head pointer**: the only entry point to the entire list — lose it and the list is lost
- **Heap allocation** for nodes (`new Node()`) — nodes live on the Heap, not the Stack
- **Traversal** using a temporary pointer (`current`) — never move `head` itself
- **Single pointer rule**: inspect and act on the current node *before* moving to `next`
- **Edge cases**: empty list, single-node list, operating on the first or last node
- **Memory cleanup**: `delete` every node after use to prevent Memory Leak
- **Doubly Linked List**: each node holds both `next` and `prev` pointers — enables bidirectional traversal
- **Cycle detection** using Floyd's slow/fast pointer algorithm
### Key Rules Learned
 
```cpp
// Node definition
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
 
// NEVER move head — always use a temp pointer
Node* current = head;
while (current != nullptr) {
    // act on current node FIRST, then move
    cout << current->data << " ";
    current = current->next;
}
```
 
```cpp
// Insert at front — O(1)
Node* newNode = new Node(val);
newNode->next = head;
head = newNode;
 
// Insert at end — O(n)
Node* current = head;
while (current->next != nullptr)   // stop at last node, not nullptr
    current = current->next;
current->next = new Node(val);
```
 
```cpp
// Delete a node safely
Node* temp = target;
previousNode->next = target->next;  // bypass the node
delete temp;                         // free its memory
temp = nullptr;
```
 
```cpp
// Reverse a Linked List — three-pointer technique
Node* prev    = nullptr;
Node* current = head;
Node* next    = nullptr;
 
while (current != nullptr) {
    next          = current->next;  // save next before overwriting
    current->next = prev;           // flip the pointer
    prev          = current;        // advance prev
    current       = next;           // advance current
}
head = prev;  // new head is the old tail
```
 
```cpp
// Detect cycle — Floyd's Algorithm
Node* slow = head;
Node* fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;  // cycle found
}
return false;
```
 
### Array vs Linked List — When to Use Which
 
| Operation | Array | Linked List |
|-----------|-------|-------------|
| Access element by index | **O(1)** ← winner | O(n) |
| Insert / Delete at **front** | O(n) | **O(1)** ← winner |
| Insert / Delete at **end** | O(1) with size tracking | O(n) without tail pointer |
| Insert / Delete in **middle** | O(n) | O(n) — but no shifting |
| Memory layout | Contiguous | Scattered on Heap |
| Memory overhead | Low | Extra pointer per node |
| **Use when** | Random access needed | Frequent front insertions / deletions |
 
> **GIS relevance:** Linked Lists power undo/redo history in GIS tools, event queues in spatial processing pipelines, and adjacency lists in graph-based network analysis.
 
### Common Mistakes to Avoid
 
| Mistake | Problem | Fix |
|---------|---------|-----|
| Moving `head` during traversal | List is lost permanently | Always use a `temp` or `current` copy |
| Forgetting to handle empty list | Crash on `head->data` | Check `if (head == nullptr)` first |
| Checking `current->next == nullptr` to stop | Skips processing last node | Check `current != nullptr` instead |
| Using two pointers when one is enough | Unnecessary complexity | Act on node first, then move |
| Forgetting `delete` on removed nodes | Memory Leak | Always `delete` then set to `nullptr` |
| Not updating `head` after front deletion | Dangling pointer | `head = head->next` before `delete` |
| `while (current->next->next != nullptr)` without null check | Crash on 1-node list | Always guard against `nullptr` before chaining |
 
### Files
 
| File | What it does |
|------|-------------|
| `Traversal.cpp` | Creates a linked list of 5 nodes manually, links them, and prints all values via single-pass traversal |
| `Extract_length_and_maximum_value.cpp` | Prints all values via single-pass traversal that counts nodes and finds the maximum value |
| `Recursive_reverse_print.cpp` | Take (N) values from user and Print it by reverse via single-pass traversal |
| `Insert_at_front.cpp` | Take (N) value from user and append it in front via single-pass traversal |
| `Insert_at_end.cpp` | Take (N) value from user and append it in end via single-pass traversal |
| `Search.cpp` | Searches for a target value in a user-created linked list |
| `Delete_at_front.cpp` | Builds a linked list from user input, delete the first node and displays the result |
| `Delete_at_end.cpp` | Builds a linked list from user input, delete the last node and displays the result |
| `Insert_before_position.cpp` | Creates a linked list of 5 elements, inserts a new node at a user-specified position, and shows the size increase |
| `Insert_before_Value.cpp` | Creates a linked list of 5 elements, inserts a new node at a user-specified value, and shows the size increase |
| `Delete_at_Position.cpp` | Creates a linked list of 5 elements, then deletes the node at a user-specified position and displays the updated list |
| `Delete_at_value.cpp` | Creates a linked list of 5 elements, then deletes the node at a user-specified value and displays the updated list |
| `Reverse_linked_list.cpp` | Creates a linked list of 5 elements, then reverse it and displays before and after |
| `Music_playlist_circular.cpp` | Implements a circular linked list music playlist with next, previous, add, delete, display, and quit functionality |

---
 
## 🧠 Key Concepts Summary
 
### Memory Layout
 
```
Stack                    Heap
|----------|            |----------|
| int x=5  |            |   [10]   | ← new int(10)
| int* p --|----------> | address  |
|----------|            |----------|
```
 
### Array in Memory
 
```
arr[0]  arr[1]  arr[2]  arr[3]  arr[4]
  10      20      30      40      50
 1000    1004    1008    1012    1016   ← addresses (int = 4 bytes)
  ↑
arr (pointer to first element)
```
 
### Linked List in Memory
 
```
head
 ↓
[10 | 0x200] ──→ [20 | 0x300] ──→ [30 | nullptr]
  0x100              0x200              0x300
  (Stack)            (Heap)             (Heap)
 
Nodes are scattered in Heap — connected only through pointers
```
 
### Choosing the Right Structure
 
```
Need fast random access?          → Array / Vector
Frequent insert/delete at front?  → Linked List
Undo/Redo history?                → Doubly Linked List
Queue / Stack implementation?     → Linked List
Graph adjacency representation?   → Linked List of lists
```
 
### Common Mistakes to Avoid
 
| Mistake | Problem | Fix |
|---------|---------|-----|
| Forget `delete` | Memory Leak | Always `delete` after `new` |
| Forget `nullptr` after `delete` | Dangling Pointer | Always set `p = nullptr` |
| Use `delete` instead of `delete[]` for arrays | Undefined behavior | Use `delete[]` for arrays |
| Reassign pointer without `delete` | Memory Leak | `delete` first, then reassign |
| `i <= size` in loop | Out-of-bounds access | Always use `i < size` |
| `arr[size]` access | Undefined behavior | Last valid index is `size - 1` |
| Initialize with `arr[0]` then loop from `i = 0` | Counts `arr[0]` twice | If you initialize a variable with `arr[0]`, always start the loop from `i = 1` |
| Moving `head` during LL traversal | List permanently lost | Always copy to `current` first |
| Two pointers when one suffices | Unnecessary complexity | Act on node before moving |
 
---

Here's the Stack section formatted exactly like the other sections in your README:

---

## 📌 04 — Stacks

### Why Stacks?

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle — the last element added is the first one removed. Think of a stack of plates: you add a new plate on top, and when you need a plate, you take from the top first.

```
Stack (LIFO):
Push 10 →     [10]
Push 20 →   [20, 10]
Push 30 → [30, 20, 10]
Pop()    →     [20, 10]  ← 30 is removed (last in, first out)
```

### Concepts Covered

- **LIFO (Last In, First Out)** — the fundamental rule of Stack behavior
- **Stack operations**: `Push`, `Pop`, `Peek` / `Top`, `IsEmpty`
- **Two implementation approaches**:
  - **Array-based Stack** — fixed capacity, simple and fast
  - **Linked List-based Stack** — dynamic size, no overflow
- **Top pointer** — the only entry point to the stack
- **Overflow** (array version) — trying to push when stack is full
- **Underflow** — trying to pop from an empty stack
- **Peek vs Pop** — Peek views the top without removing; Pop removes it
- **Time Complexity** — all operations are **O(1)** 🔥

### Key Rules Learned

```cpp
// Stack Node (Linked List based)
struct Node {
    int Data;
    Node* Next;
};

Node* Top = nullptr;  // Points to top element
```

```cpp
// Push — add element to top
void Push(int Value) {
    Node* NewNode = new Node();
    NewNode->Data = Value;
    NewNode->Next = Top;  // New node points to old top
    Top = NewNode;        // Update top pointer
}
```

```cpp
// Pop — remove element from top
void Pop() {
    if (IsEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node* Del = Top;
    Top = Top->Next;
    delete Del;
}
```

```cpp
// Peek — view top element without removing
int Peek() {
    if (IsEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return Top->Data;
}
```

```cpp
// IsEmpty — check if stack has no elements
bool IsEmpty() {
    return Top == nullptr;
}
```

### Stack Implementations — Which to Use?

| Implementation | Pros | Cons |
|----------------|------|------|
| **Array-based** | Fast, cache-friendly | Fixed size (overflow risk) |
| **Linked List-based** | Dynamic size, no overflow | Extra memory for pointers |

> **When to use which:** Use **array-based** when you know the maximum size in advance. Use **linked list-based** when size is unknown or dynamic — exactly what we built here.

### Real-World Applications

| Application | How Stack is Used |
|-------------|-------------------|
| **Undo/Redo in GIS software** | Each edit pushed to stack; Undo = Pop |
| **Function call stack** | Stores return addresses and local variables |
| **Back button in browser** | URLs pushed when visiting; Back = Pop |
| **Parentheses matching** | Push opening brackets; Pop when closing |
| **Expression evaluation** | Convert infix to postfix, then evaluate |
| **Depth-First Search (DFS)** | Graph traversal algorithm |
| **GIS Path Analysis** | Backtracking in routing algorithms |

### Common Mistakes to Avoid

| Mistake | Problem | Fix |
|---------|---------|-----|
| Forgetting `IsEmpty()` check before `Pop` | Pop from empty stack (underflow) | Always check `IsEmpty()` first |
| Forgetting `IsEmpty()` check before `Peek` | Accessing Top when null (crash) | Always check `IsEmpty()` first |
| Not updating `Top` after `Pop` | Dangling pointer / memory leak | `Top = Top->Next` before `delete` |
| Forgetting `delete` after `Pop` | Memory leak | Always `delete` popped nodes |
| Pushing without checking capacity (array version) | Stack overflow | Check `if (top == MAX-1)` first |
| Losing `Top` pointer | Entire stack lost | Never move `Top` except through Push/Pop |

### Files

| File | What it does |
|------|-------------|
| `Stack_linked_list.cpp` | Creates a stack using linked list, allows push, pop, peek, display, and search operations through an interactive menu |
| `STL_stack_demo.cpp` | Demonstrates STL stack operations: push, pop, top, size, empty, emplace, and swap |
| `Stack_array_static.cpp` | Implements a fixed-size stack using an array with push, pop, peek, and display operations |
| `Stack_array_dynamic.cpp` | Creates a dynamic array-based stack with user-defined size, then performs push, pop, peek, and display operations |

---

## 🧠 Key Concepts Summary

| Operation | Code | Time Complexity | Description |
|-----------|------|-----------------|-------------|
| `Push(x)` | `Top = new Node(x, Top)` | O(1) | Add element to top |
| `Pop()` | `Top = Top->Next; delete old` | O(1) | Remove top element |
| `Peek()` | `return Top->Data` | O(1) | View top element |
| `IsEmpty()` | `return Top == nullptr` | O(1) | Check if stack empty |
| `Display()` | Traverse from Top | O(n) | Print all elements |

---

### Linked List-based Stack in Memory

```
After Push(10):          After Push(20):          After Push(30):
                         
    Top                      Top                      Top
     ↓                        ↓                        ↓
   [10]                    [20]                     [30]
   null                     ↓                        ↓
                          [10]                     [20]
                          null                      ↓
                                                  [10]
                                                  null

After Pop():             After Pop():
    Top                      Top
     ↓                        ↓
   [20]                     [10]
    ↓                       null
   [10]
   null
```

### Array-based Stack in Memory

```
Array: [10][20][30][ ][ ]    Top = 2 (points to index 2)
        ↑
      Push 40 → [10][20][30][40][ ]    Top = 3
      Pop()    → [10][20][30][ ][ ]    Top = 2  (value 40 removed)
```

## 📌 05 — Queues
 
### Why Queues?
 
A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle — the first element added is the first one removed. Think of a line at a ticket counter: the person who arrived first gets served first.
 
```
Queue (FIFO):
Enqueue 10 →  Front [10] Rear
Enqueue 20 →  Front [10, 20] Rear
Enqueue 30 →  Front [10, 20, 30] Rear
Dequeue()  →  Front [20, 30] Rear   ← 10 removed (first in, first out)
```
 
The critical difference from a Stack: a Stack has **one** access point (top). A Queue has **two** — `Front` for removal, `Rear` for insertion.
 
### Concepts Covered
 
- **FIFO (First In, First Out)** — the fundamental rule of Queue behavior
- **Two access points**: `Front` (Dequeue side) and `Rear` (Enqueue side)
- **Queue operations**: `Enqueue`, `Dequeue`, `Peek` / `Front`, `IsEmpty`
- **Three implementation approaches**:
  - **Linked List-based Queue** — dynamic size, no overflow, two pointers (Front + Rear)
  - **Array-based Queue (Static)** — fixed capacity, simple but wastes space after Dequeue
  - **Circular Array Queue** — fixes wasted space using modulo arithmetic
- **Underflow** — trying to Dequeue from an empty queue
- **Overflow** — trying to Enqueue when circular array is full
- **Deque (Double-Ended Queue)** — insert and remove from both ends
- **Time Complexity** — all main operations are **O(1)** 🔥
### Key Rules Learned
 
```cpp
// Queue Node (Linked List based)
struct Node {
    int Data;
    Node* Next;
};
 
Node* Front = nullptr;  // Points to first element (Dequeue side)
Node* Rear  = nullptr;  // Points to last element  (Enqueue side)
```
 
```cpp
// Enqueue — add element at Rear
void Enqueue(int Value) {
    Node* NewNode = new Node();
    NewNode->Data = Value;
    NewNode->Next = nullptr;      // New node is always the last
 
    if (IsEmpty()) {
        Front = Rear = NewNode;   // First element: both pointers point to it
    } else {
        Rear->Next = NewNode;     // Link current last to new node
        Rear = NewNode;           // Move Rear forward
    }
}
```
 
```cpp
// Dequeue — remove element from Front
void Dequeue() {
    if (IsEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node* Del = Front;
    Front = Front->Next;          // Move Front forward
 
    if (Front == nullptr)         // If queue became empty
        Rear = nullptr;           // Reset Rear too — critical!
 
    delete Del;
}
```
 
```cpp
// Peek — view Front element without removing
int Peek() {
    if (IsEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return Front->Data;
}
```
 
```cpp
// IsEmpty — check if queue has no elements
bool IsEmpty() {
    return Front == nullptr;
}
```
 
```cpp
// Circular Array Queue — the smarter array approach
// Uses modulo to wrap around and reuse empty slots
 
struct CircularQueue {
    int* arr;
    int front, rear, size, capacity;
 
    CircularQueue(int cap) {
        capacity = cap;
        arr   = new int[capacity];
        front = rear = -1;
        size  = 0;
    }
 
    bool IsFull()  { return size == capacity; }
    bool IsEmpty() { return size == 0; }
 
    void Enqueue(int val) {
        if (IsFull()) { cout << "Queue Full!\n"; return; }
        rear  = (rear + 1) % capacity;   // wrap around with modulo
        arr[rear] = val;
        if (front == -1) front = 0;
        size++;
    }
 
    void Dequeue() {
        if (IsEmpty()) { cout << "Queue Empty!\n"; return; }
        front = (front + 1) % capacity;  // wrap around with modulo
        size--;
        if (size == 0) front = rear = -1;
    }
 
    int Peek() {
        if (IsEmpty()) return -1;
        return arr[front];
    }
 
    ~CircularQueue() { delete[] arr; arr = nullptr; }
};
```
 
```cpp
// Deque — double-ended queue using STL
#include <deque>
 
deque<int> dq;
dq.push_back(10);   // add at rear
dq.push_front(5);   // add at front
dq.pop_back();      // remove from rear
dq.pop_front();     // remove from front
dq.front();         // view front element
dq.back();          // view rear element
```
 
### Queue Implementations — Which to Use?
 
| Implementation | Pros | Cons |
|----------------|------|------|
| **Linked List-based** | Dynamic size, no overflow, no wasted slots | Extra memory for pointers |
| **Array-based (Static)** | Cache-friendly, simple | Fixed size + wasted slots after Dequeue |
| **Circular Array** | No wasted slots, fixed memory | More complex index logic |
| **STL `queue`** | Ready to use, no manual memory | Less control over internals |
| **STL `deque`** | Insert/remove from both ends | Slightly more memory overhead |
 
> **When to use which:** Use **linked list-based** when size is unpredictable. Use **circular array** when you need fixed-memory FIFO (embedded systems, buffers). Use **STL** in real projects.
 
### Real-World Applications
 
| Application | How Queue is Used |
|-------------|-------------------|
| **GIS Task Scheduler** | Spatial analysis jobs queued and processed in order |
| **BFS (Breadth-First Search)** | Explores graph nodes level by level — uses Queue |
| **Print Spooler** | Print jobs queued; processed in order received |
| **Network Packet Buffering** | Data packets held in order before transmission |
| **Undo history with limit** | Circular queue holds last N actions only |
| **CPU Process Scheduling** | OS processes queued for execution time |
| **Keyboard Input Buffer** | Keystrokes stored in order before processing |
| **GIS Route Processing** | Waypoints queued for sequential path analysis |
 
### Common Mistakes to Avoid
 
| Mistake | Problem | Fix |
|---------|---------|-----|
| Forgetting `IsEmpty()` check before `Dequeue` | Dequeue from empty queue (crash) | Always check `IsEmpty()` first |
| Forgetting `IsEmpty()` check before `Peek` | Accessing `Front` when null (crash) | Always check `IsEmpty()` first |
| Not resetting `Rear = nullptr` when queue becomes empty | `Rear` points to deleted memory | After last Dequeue, set both `Front = Rear = nullptr` |
| Forgetting `delete` after `Dequeue` | Memory Leak | Always `delete` dequeued nodes |
| Confusing `Front` and `Rear` roles | Enqueue at Front / Dequeue at Rear | `Enqueue` → `Rear`, `Dequeue` → `Front` |
| Static array Queue — reusing freed front slots | Wasted memory | Use **Circular Queue** with modulo instead |
| Wrong modulo in Circular Queue | Index goes out of bounds | Always `(index + 1) % capacity` |
| Not updating `Front` when using Circular Queue | Front frozen at old slot | Move `Front = (Front + 1) % capacity` after each Dequeue |
| Treating Queue like a Stack | Wrong order of processing | Queue = FIFO; Stack = LIFO — never confuse them |
 
### Files
 
| File | What it does |
|------|-------------|
| `Queue_linked_list.cpp` | Implements a FIFO queue using a linked list with enqueue, dequeue, peek, display, count, search, and cleanup operations |
| `Queue_array.cpp` | Implements a FIFO queue using a fixed-size array (vector) with enqueue, dequeue, display, peek, clean, and search operations |
| `Circular_queue_array.cpp` | Implements a circular queue using a fixed-size array with wrap-around functionality to reuse empty spaces |
| `STL_queue_demo.cpp` | Demonstrates STL queue operations: push, pop, front, back, size, empty, emplace, and swap |


---
 
## 🧠 Key Concepts Summary — Queues
 
| Operation | Code (Linked List) | Time Complexity | Description |
|-----------|-------------------|-----------------|-------------|
| `Enqueue(x)` | `Rear->Next = new Node(x); Rear = Rear->Next` | O(1) | Add element at Rear |
| `Dequeue()` | `Front = Front->Next; delete old` | O(1) | Remove element from Front |
| `Peek()` | `return Front->Data` | O(1) | View Front element without removing |
| `IsEmpty()` | `return Front == nullptr` | O(1) | Check if queue is empty |
| `Display()` | Traverse from Front to Rear | O(n) | Print all elements |
 
---
 
### Linked List-based Queue in Memory
 
```
After Enqueue(10):        After Enqueue(20):        After Enqueue(30):
 
Front/Rear                Front          Rear        Front          Rear
   ↓                        ↓              ↓            ↓              ↓
  [10]                    [10]  ───→    [20]          [10] ──→ [20] ──→ [30]
  null                    null                        null
 
After Dequeue():          After Dequeue():
 
Front      Rear           Front/Rear
  ↓          ↓               ↓
[20] ──→  [30]             [30]
          null              null
```
 
### Circular Array Queue in Memory
 
```
capacity = 5
 
Initial:   [ ][ ][ ][ ][ ]    front = -1,  rear = -1
 
Enqueue 10: [10][ ][ ][ ][ ]  front = 0,   rear = 0
Enqueue 20: [10][20][ ][ ][ ] front = 0,   rear = 1
Enqueue 30: [10][20][30][ ][ ] front = 0,  rear = 2
Dequeue():  [ ][20][30][ ][ ] front = 1,   rear = 2  ← slot 0 freed
Dequeue():  [ ][ ][30][ ][ ]  front = 2,   rear = 2  ← slot 1 freed
 
Enqueue 40: [ ][ ][30][40][ ] front = 2,   rear = 3
Enqueue 50: [ ][ ][30][40][50] front = 2,  rear = 4
Enqueue 60: [60][ ][30][40][50] front = 2, rear = 0  ← wraps around! (rear = (4+1) % 5 = 0)
                                                         reuses freed slot 0
```
 
### Circular Queue Formulas:
| Operation	| Formula |
|-----------|---------|
| Next position	| (index + 1) % size |
| Previous position | (index - 1 + size) % size |
| IsFull condition | (rear + 1) % size == front |
| IsEmpty condition	| front == -1 && rear == -1 |

### Queue vs Stack — The Key Difference
 
```
Stack (LIFO)           Queue (FIFO)
 One opening            Two openings
    ↕                    →  [  ] →
  [30]                  Front    Rear
  [20]                  (remove) (add)
  [10]
  ────
```
 
### Choosing the Right Structure
 
```
Need LIFO? (last in = first out)          → Stack
Need FIFO? (first in = first out)         → Queue
Need insert/remove from BOTH ends?        → Deque
Need fixed-size buffer (no extra memory)? → Circular Queue
Need BFS graph traversal?                 → Queue
Need DFS graph traversal?                 → Stack
```

---
 
 
# 🌿 Part 2 — Non-Linear Data Structures
 
> Structures where elements are NOT arranged sequentially.
> Each element can connect to multiple elements, forming hierarchies or networks.
 
---
 
## 📌 06 — Trees
 
### Why Trees?
 
Linear structures (Array, Linked List, Stack, Queue) force elements into a single line. But many real-world problems are **hierarchical** by nature — file systems, organization charts, geographic region hierarchies, and network topologies all have parent-child relationships that a line can't model.
 
A **Tree** solves this: instead of each node pointing to one next node, a node can point to **multiple children**, forming a branching structure.
 
```
Linear (Linked List):   [10] → [20] → [30] → [40] → NULL
                         one direction, one connection per node
 
Tree:                           [Root]
                               /  |  \
                             [A] [B] [C]
                            / \   |  / | \
                          [X] [L][M][D][E][F]
                         hierarchical, branching, multi-connection
```
 
> **GIS relevance:** Trees power spatial indexing (R-Tree, QuadTree) used in ArcGIS for fast bounding-box queries, region hierarchies (continent → country → city), decision trees in spatial analysis, and Binary Space Partitioning in 3D GIS rendering.
 
---
 
### Tree Terminology — Visual Reference
 
```
                        [ Root ]          ← Level 0  (Depth = 0)
                       /    |    \
                     [A]   [B]   [C]      ← Level 1  (Depth = 1)
                    /  \    |   / | \
                  [X]  [L] [M] [D][E][F]  ← Level 2  (Depth = 2)
                                           ← Leaf nodes (no children)
 
Height of Tree = 2  (number of edges on longest path from Root to any Leaf)
Degree of Root = 3  (has 3 children: A, B, C)
Degree of A    = 2  (has 2 children: X, L)
Degree of Tree = 3  (max degree among all nodes)
```
 
---
 
### Concepts Covered
 
#### Core Vocabulary
 
| Term | Definition |
|------|-----------|
| **Node** | Basic unit of a tree — holds data and pointers to children |
| **Edge** | The link/connection between a Parent node and a Child node |
| **Root** | The topmost node — has no parent; entry point to the entire tree |
| **Leaf Node** | A node with **no children** — represents the end of a branch |
| **Internal Node** | Any node that is neither Root nor Leaf — has both a parent and children |
| **External Node** | Root and Leaf nodes — the boundary nodes of the tree |
| **Parent** | A node that has one or more children |
| **Child** | A node that has a parent |
| **Siblings** | Nodes that share the same parent (e.g., D, E, F are siblings — all children of C) |
| **Ancestors** | All nodes on the path from a given node up to the Root |
| **Subtree** | Any node together with all its descendants — can be treated as an independent tree |
| **Forest** | A collection of disjoint trees |
 
#### Measurement Vocabulary
 
| Term | Definition | Formula / Example |
|------|-----------|------------------|
| **Level** | Horizontal layer of nodes — Root is Level 0 | Increases by 1 going downward |
| **Depth of a Node** | Number of edges from Root to that node | Always equals the node's Level value |
| **Height of a Node** | Number of edges on the longest path from that node to any Leaf below it | `LastLevel − NodeLevel` |
| **Height of Tree** | Number of edges on the longest path from Root to any Leaf | Equals the number of the last Level |
| **Degree of a Node** | Number of children that node has | Root in example above: degree = 3 |
| **Degree of Tree** | Maximum degree found among all nodes in the tree | = degree of the node with most children |
 
#### Directional Nature
 
A Tree is **directional**: edges flow from Parent → Child, never in reverse. If C points to D, E, F — that means C is the parent, not the children. You **cannot** traverse upward (from D to C) unless the tree explicitly stores a `parent` pointer.
 
#### Relative Terms
 
"Parent" and "Child" are **relative** — the same node can be both:
- A is a **Child** of Root
- A is a **Parent** of X and L
```
Root → Parent of A, B, C
A    → Child  of Root   AND   Parent of X, L
X    → Child  of A      AND   Leaf (no children → degree 0)
```
 
---
 
### Node Structure in C++
 
```cpp
// Generic Tree Node — can have multiple children
struct TreeNode {
    int Data;
    TreeNode* Children[MAX_CHILDREN];  // array of child pointers
    int ChildCount;
 
    TreeNode(int val) : Data(val), ChildCount(0) {
        for (int i = 0; i < MAX_CHILDREN; i++)
            Children[i] = nullptr;
    }
};
```
 
```cpp
// Binary Tree Node — exactly 0, 1, or 2 children
struct BinaryNode {
    int Data;
    BinaryNode* Left;    // left child
    BinaryNode* Right;   // right child
 
    BinaryNode(int val) : Data(val), Left(nullptr), Right(nullptr) {}
};
```
 
> **Key difference from Linked List:** A Linked List node has ONE `next` pointer. A Tree node has TWO or MORE child pointers — that's what makes it non-linear.
 
---
 
### Types of Trees
 
#### 1. General Tree
- Each node can have **any number** of children (no restriction)
- Used for: file systems, organizational charts, XML/HTML DOM
```
        [CEO]
       /  |  \
    [VP1][VP2][VP3]
    /  \       |
 [Mgr1][Mgr2][Mgr3]
```
 
#### 2. Binary Tree
- Each node has **at most 2 children**: Left and Right
- The foundation for most other tree types
- Subtypes:
| Subtype | Rule |
|---------|------|
| **Full Binary Tree** | Every node has exactly 0 or 2 children (never 1) |
| **Complete Binary Tree** | All levels fully filled except possibly the last; last level filled left to right |
| **Perfect Binary Tree** | All internal nodes have exactly 2 children AND all leaves are at the same level |
| **Binary Search Tree (BST)** | Left child < Parent < Right child — enables fast search |
 
```
Binary Tree:          Complete Binary Tree:      Perfect Binary Tree:
     [1]                     [1]                        [1]
    /   \                   /   \                      /   \
  [2]   [3]              [2]   [3]                  [2]   [3]
  /                      / \   /                   / \   / \
[4]                    [4][5][6]                 [4][5][6][7]
```
 
#### 3. Binary Search Tree (BST)
- Left subtree contains only values **less than** the parent
- Right subtree contains only values **greater than** the parent
- This property applies **recursively** at every node
```
         [50]
        /    \
      [30]   [70]
      / \    / \
   [20][40][60][80]
 
Search for 60:
  Start at 50 → 60 > 50 → go Right
  At 70       → 60 < 70 → go Left
  At 60       → Found! ✓   (only 2 comparisons, not 6)
```
 
#### 4. Heap (Min-Heap / Max-Heap)
- A **Complete Binary Tree** that satisfies the Heap property
- **Max-Heap**: every parent ≥ its children → root holds the maximum value
- **Min-Heap**: every parent ≤ its children → root holds the minimum value
- Used for: Priority Queues, sorting (Heap Sort), finding k-th largest/smallest
```
Max-Heap:          Min-Heap:
    [90]               [5]
   /    \             /   \
 [70]  [80]         [10]  [8]
 / \   /            / \
[50][60][75]      [20][15]
```
 
#### 5. AVL Tree (Balanced BST)
- A BST that **self-balances** after every insertion or deletion
- Balance condition: for every node, the height difference between left and right subtrees is **at most 1**
- Guarantees O(log n) operations even in worst case
#### 6. Red-Black Tree
- A self-balancing BST with less strict balance than AVL
- Used internally by C++ `std::map` and `std::set`
- Slightly faster insertions/deletions than AVL; slightly slower lookups
---
 
### Tree Traversals
 
Traversal means visiting every node exactly once. Unlike linear structures (just go front-to-back), trees offer **multiple valid orders**:
 
#### Depth-First Traversals (use Stack / Recursion)
 
```
Tree:
       [1]
      /   \
    [2]   [3]
    / \
  [4] [5]
```
 
**Preorder (Root → Left → Right)**
```
Visit: 1 → 2 → 4 → 5 → 3
Rule: Process the node FIRST, then recurse into children
Use: Copy a tree, serialize tree structure
```
 
```cpp
void Preorder(BinaryNode* node) {
    if (node == nullptr) return;
    cout << node->Data << " ";   // process Root
    Preorder(node->Left);        // recurse Left
    Preorder(node->Right);       // recurse Right
}
```
 
**Inorder (Left → Root → Right)**
```
Visit: 4 → 2 → 5 → 1 → 3
Rule: Recurse Left FIRST, then process, then recurse Right
Use: Produces SORTED output when applied to a BST ← very important!
```
 
```cpp
void Inorder(BinaryNode* node) {
    if (node == nullptr) return;
    Inorder(node->Left);         // recurse Left
    cout << node->Data << " ";   // process Root
    Inorder(node->Right);        // recurse Right
}
```
 
**Postorder (Left → Right → Root)**
```
Visit: 4 → 5 → 2 → 3 → 1
Rule: Recurse into BOTH children first, process node last
Use: Delete a tree (free children before parent), evaluate expression trees
```
 
```cpp
void Postorder(BinaryNode* node) {
    if (node == nullptr) return;
    Postorder(node->Left);       // recurse Left
    Postorder(node->Right);      // recurse Right
    cout << node->Data << " ";   // process Root (last)
}
```
 
#### Breadth-First Traversal (use Queue)
 
**Level-Order (BFS)**
```
Visit: 1 → 2 → 3 → 4 → 5
Rule: Visit all nodes at current level before going deeper
Use: Find shortest path, BFS in graphs, print tree level by level
```
 
```cpp
void LevelOrder(BinaryNode* root) {
    if (root == nullptr) return;
 
    queue<BinaryNode*> q;
    q.push(root);
 
    while (!q.empty()) {
        BinaryNode* current = q.front();
        q.pop();
 
        cout << current->Data << " ";   // process node
 
        if (current->Left)  q.push(current->Left);   // enqueue left child
        if (current->Right) q.push(current->Right);  // enqueue right child
    }
}
```
 
#### Traversal Comparison
 
| Traversal | Order | Uses Recursion/Stack | Main Use |
|-----------|-------|---------------------|----------|
| **Preorder** | Root → L → R | Recursion (Stack) | Copy tree, serialize |
| **Inorder** | L → Root → R | Recursion (Stack) | Sorted output from BST |
| **Postorder** | L → R → Root | Recursion (Stack) | Delete tree, evaluate expressions |
| **Level-Order** | Level by Level | Queue (BFS) | Shortest path, level printing |
 
---
 
### Key Operations on Binary Search Tree (BST)
 
```cpp
// Search — O(h) where h = height of tree
BinaryNode* Search(BinaryNode* root, int target) {
    if (root == nullptr || root->Data == target)
        return root;                         // found or not in tree
 
    if (target < root->Data)
        return Search(root->Left, target);   // go left
    else
        return Search(root->Right, target);  // go right
}
```
 
```cpp
// Insert — O(h)
BinaryNode* Insert(BinaryNode* root, int val) {
    if (root == nullptr)
        return new BinaryNode(val);          // found empty spot → insert here
 
    if (val < root->Data)
        root->Left  = Insert(root->Left, val);   // recurse left
    else if (val > root->Data)
        root->Right = Insert(root->Right, val);  // recurse right
    // if val == root->Data → duplicate, do nothing
 
    return root;
}
```
 
```cpp
// Find Minimum — always the leftmost node
BinaryNode* FindMin(BinaryNode* root) {
    while (root->Left != nullptr)
        root = root->Left;
    return root;
}
```
 
```cpp
// Delete — O(h)  — three cases
BinaryNode* Delete(BinaryNode* root, int val) {
    if (root == nullptr) return nullptr;
 
    if (val < root->Data) {
        root->Left  = Delete(root->Left, val);   // search left
    } else if (val > root->Data) {
        root->Right = Delete(root->Right, val);  // search right
    } else {
        // Found the node to delete — three cases:
 
        // Case 1: Leaf node (no children) — just delete
        if (root->Left == nullptr && root->Right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child — replace node with its child
        else if (root->Left == nullptr) {
            BinaryNode* temp = root->Right;
            delete root;
            return temp;
        }
        else if (root->Right == nullptr) {
            BinaryNode* temp = root->Left;
            delete root;
            return temp;
        }
        // Case 3: Two children — replace with Inorder Successor (min of right subtree)
        else {
            BinaryNode* successor = FindMin(root->Right);
            root->Data = successor->Data;                      // copy successor's value
            root->Right = Delete(root->Right, successor->Data); // delete successor
        }
    }
    return root;
}
```
 
---
 
### Height & Depth Calculations
 
```cpp
// Calculate height of a tree
int Height(BinaryNode* root) {
    if (root == nullptr) return -1;  // empty tree has height -1
    int leftHeight  = Height(root->Left);
    int rightHeight = Height(root->Right);
    return 1 + max(leftHeight, rightHeight);
}
```
 
```cpp
// Count total nodes in a tree
int CountNodes(BinaryNode* root) {
    if (root == nullptr) return 0;
    return 1 + CountNodes(root->Left) + CountNodes(root->Right);
}
```
 
---
 
### Time Complexity — BST Operations
 
| Operation | Average Case (Balanced) | Worst Case (Skewed) |
|-----------|------------------------|---------------------|
| **Search** | O(log n) | O(n) |
| **Insert** | O(log n) | O(n) |
| **Delete** | O(log n) | O(n) |
| **Traversal** | O(n) | O(n) |
| **Find Min/Max** | O(log n) | O(n) |
 
> **Why worst case O(n)?** If you insert sorted data (1, 2, 3, 4, 5...) into a BST, every node goes to the right — creating a straight line, not a tree. This is why **Balanced Trees** (AVL, Red-Black) exist.
 
```
Balanced BST (h = log n):       Skewed BST (h = n):
         [4]                     [1]
        /   \                      \
      [2]   [6]                    [2]
      / \   / \                      \
    [1][3][5][7]                     [3]
                                       \
    Search = 3 steps max              [4]
                                         \
                                         [5]  ← Search = 5 steps
```
 
---
 
### Tree vs Other Data Structures
 
| Feature | Array | Linked List | Stack / Queue | BST (Balanced) |
|---------|-------|-------------|---------------|----------------|
| **Access by index** | O(1) | O(n) | ✗ | ✗ |
| **Search** | O(n) | O(n) | ✗ | **O(log n)** |
| **Insert (ordered)** | O(n) | O(n) | O(1) at one end | **O(log n)** |
| **Delete (ordered)** | O(n) | O(n) | O(1) at one end | **O(log n)** |
| **Memory layout** | Contiguous | Scattered | Depends | Scattered (Heap) |
| **Hierarchy support** | ✗ | ✗ | ✗ | ✓ |
 
---
 
### Visualizing Tree Structure in Memory
 
```
BinaryNode* root = new BinaryNode(50);
                          root
Stack:  | root ptr |       ↓
        |----------|    [50 | L | R ]  ← on Heap
                           ↓      ↓
                       nullptr  nullptr
 
After Insert(30):         root
                           ↓
                       [50 | L | R]
                           ↓
                   [30 | null | null]   ← Left child
 
After Insert(70):         root
                           ↓
                      [50 | L  |  R]
                          ↓       ↓
                    [30|n|n]   [70|n|n]
```
 
---
 
### Real-World Applications
 
| Application | How Tree is Used |
|-------------|-----------------|
| **GIS Spatial Indexing (R-Tree / QuadTree)** | Fast bounding-box queries — "find all features in this viewport" |
| **ArcGIS Geodatabase Schema** | Feature classes, subtypes, domains form a hierarchy |
| **Geographic Hierarchy** | Continent → Country → Governorate → City → District |
| **File System** | Directories are parent nodes; files are leaf nodes |
| **HTML/XML DOM** | Document structure represented as a tree |
| **Priority Queue (Heap)** | Task scheduling by priority in spatial processing pipelines |
| **BST for Sorted Data** | Fast lookup, insertion, deletion while maintaining sorted order |
| **Expression Evaluation** | Math expression trees: `(3 + 4) * 2` stored as a tree |
| **Decision Trees in Spatial ML** | Classification of land use, vegetation, flood zones |
| **Huffman Coding** | Data compression — building optimal encoding trees |
 
---
 
### Common Mistakes to Avoid
 
| Mistake | Problem | Fix |
|---------|---------|-----|
| Forgetting base case `if (root == nullptr) return` in recursion | Infinite recursion / crash | Always check for null before accessing node data |
| Confusing Inorder with Preorder | Wrong output order | Remember: In = L-Root-R, Pre = Root-L-R, Post = L-R-Root |
| Deleting a node with two children without finding Inorder Successor | Breaks BST property | Always replace with min of right subtree (or max of left) |
| Not freeing tree memory after use | Memory Leak | Use Postorder traversal to `delete` nodes (children before parent) |
| Inserting sorted data into unbalanced BST | O(n) degeneration | Use AVL or Red-Black Tree for guaranteed O(log n) |
| Treating tree height as number of nodes | Wrong calculations | Height = number of **edges**, not nodes, on longest path |
| Moving `root` pointer during traversal | Tree is lost | Always use a local `node` parameter, never modify `root` |
| Forgetting `return root` after recursive Insert/Delete | Tree structure broken | Insert/Delete must return the (possibly new) root of each subtree |
| Confusing Level with Depth | Wrong terminology | Both equal the same value; Level 0 = Depth 0 = Root |
| Not handling empty tree before operations | Null pointer crash | Check `if (root == nullptr)` at the start of every function |
 
---
 
### Files
 
| File | What it does |
|------|-------------|
| `Binary_search_tree.cpp` | Implements a Binary Search Tree with insert, three traversals (pre/in/post), search, min, max, and deletion operations |

---
 
## 🧠 Key Concepts Summary — Trees
 
| Operation | Code Pattern | Time Complexity | Description |
|-----------|-------------|-----------------|-------------|
| `Search(root, x)` | Recurse L or R based on comparison | O(log n) avg / O(n) worst | Find a value in BST |
| `Insert(root, x)` | Recurse to empty spot, create node | O(log n) avg / O(n) worst | Add value maintaining BST order |
| `Delete(root, x)` | Handle 3 cases; return updated root | O(log n) avg / O(n) worst | Remove node, preserve BST property |
| `Height(root)` | `1 + max(Height(L), Height(R))` | O(n) | Measure longest root-to-leaf path |
| `CountNodes(root)` | `1 + Count(L) + Count(R)` | O(n) | Count all nodes |
| `Inorder(root)` | L → Root → R | O(n) | Sorted output for BST |
| `Preorder(root)` | Root → L → R | O(n) | Copy / serialize tree |
| `Postorder(root)` | L → R → Root | O(n) | Delete tree, evaluate expressions |
| `LevelOrder(root)` | BFS with Queue | O(n) | Level-by-level traversal |
 
---
 
### BST in Memory — Step by Step
 
```
Insert sequence: 50, 30, 70, 20, 40
 
Step 1 — Insert 50:          Step 2 — Insert 30:          Step 3 — Insert 70:
        root                          root                          root
         ↓                             ↓                             ↓
       [50]                          [50]                          [50]
      L:null R:null                  /                             /   \
                                  [30]                          [30]  [70]
 
Step 4 — Insert 20:          Step 5 — Insert 40:
        root                          root
         ↓                             ↓
       [50]                          [50]
       /   \                         /   \
    [30]  [70]                    [30]  [70]
    /                             /  \
  [20]                          [20][40]
 
Inorder of final tree: 20 → 30 → 40 → 50 → 70  ← sorted! ✓
```
 
### BST Property — Quick Mental Check
 
```
For ANY node in a valid BST:
  ✓ ALL values in LEFT  subtree < node value
  ✓ ALL values in RIGHT subtree > node value
  ✓ Both subtrees are themselves valid BSTs
 
Quick check on [50,30,70,20,40]:
  Is 20 in left subtree of 50?  → 20 < 50 ✓
  Is 70 in right subtree of 50? → 70 > 50 ✓
  Is 20 in left subtree of 30?  → 20 < 30 ✓
  Is 40 in right subtree of 30? → 40 > 30 ✓  → Valid BST ✓
```
 
### Traversal Memory Aid
 
```
Pre  =  ROOT first  →  "I go first, children later"
In   =  ROOT middle →  "Left child, then me, then right child"
Post =  ROOT last   →  "Children first, I come last"
Level = floor by floor (BFS with Queue)
```
 
### Choosing the Right Tree Type
 
```
Need sorted data + fast search/insert/delete?    → BST
BST + guaranteed O(log n) in ALL cases?          → AVL Tree
BST + used by STL (map/set)?                     → Red-Black Tree
Need to find min/max instantly?                  → Heap (Min/Max)
Need fast BFS (level-order) traversal?           → any tree + Queue
Need spatial range queries in GIS?               → R-Tree / QuadTree
```
 
---

## 🎯 Goal

Become a strong **GIS Developer** by mastering:

1. ✅ Pointers & Memory Management
2. ✅ Arrays & Dynamic Arrays
3. ✅ Linked Lists 
4. ✅ Stacks 
4. ✅ Queues 
5. 🔥 Trees ← current
5. ⏳ Graphs
6. ⏳ Python for GIS + Spatial Databases
---

## 📚 Resources

- 🎥 [محمد الدسوقي — Data Structures (YouTube)](https://www.youtube.com/@mohameddesouky)
- 🎥 [Mega Code — Data Structures with C++ (YouTube)](https://www.youtube.com/@megacodeyt)
- 🎥 [Adel Nasim — Data Structures Full Course In Arabic (YouTube)](https://www.youtube.com/@AdelNasim)
- 📖 Grokking Algorithms
- 💻 LeetCode — Practice Problems
---

*"Every expert was once a beginner." — Started: March 2026*