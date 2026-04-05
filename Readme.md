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
│   └── Smallest_element.cpp
│
├── 03-linked-lists/     🔜 Coming soon
├── 04-stacks-queues/    🔜 Coming soon
└── 05-trees-graphs/     🔜 Coming soon
```

---

## ✅ Progress

| Topic | Status | Files |
|-------|--------|-------|
| Pointers & Dynamic Memory | ✅ Done | 10 files |
| Arrays | 🔥 In Progress | 3 file |
| Linked Lists | ⏳ Planned | — |
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
| `Dynamic_array_input_sum.cpp` | Creates a dynamic array of (N) integers on the heap from user, print it, and calculates the sum |

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

### Files

| File | What it does |
|------|-------------|
| `Array_reverse_output.cpp` | Takes 5 integers from user and prints them in reverse order |
| `Array_sum_with_dynamic_size_and_length.cpp` | Creates a dynamic array with user-defined size, asks user how many elements to fill (length), validates that length does not exceed size, fills the array with user input, prints all entered elements, and calculates their sum |
| `Smallest_element.cpp` | Takes (N) integers from user and Finds the smallest (minimum) value in the array |

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

---

## 🎯 Goal

Become a strong **GIS Developer** by mastering:

1. ✅ Pointers & Memory Management
2. 🔥 Arrays & Dynamic Arrays ← current
3. ⏳ Linked Lists
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