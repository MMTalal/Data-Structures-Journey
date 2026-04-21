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
│   └── Recursive_reverse_print.cpp
│
├── 04-stacks-queues/    🔜 Coming soon
└── 05-trees-graphs/     🔜 Coming soon
```

---

## ✅ Progress

| Topic | Status | Files |
|-------|--------|-------|
| Pointers & Dynamic Memory | ✅ Done | 10 files |
| Arrays | ✅ Done | 13 files |
| Linked Lists | 🔥 In Progress | 3 files |
| Stacks & Queues | ⏳ Planned | — |
| Trees & Graphs | ⏳ Planned | — |

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

## 🎯 Goal

Become a strong **GIS Developer** by mastering:

1. ✅ Pointers & Memory Management
2. ✅ Arrays & Dynamic Arrays
3. 🔥 Linked Lists ← current
4. ⏳ Stacks & Queues
5. ⏳ Trees & Graphs
6. ⏳ Python for GIS + Spatial Databases

---

## 📚 Resources

- 🎥 [محمد الدسوقي — Data Structures (YouTube)](https://www.youtube.com/@mohameddesouky)
- 📖 Grokking Algorithms
- 💻 LeetCode — Practice Problems

---

*"Every expert was once a beginner." — Started: March 2026*