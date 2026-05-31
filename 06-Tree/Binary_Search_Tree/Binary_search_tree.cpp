#include<iostream>
using namespace std;

// Node structure for Binary Search Tree (BST)
struct Node {
    int Data;       // Value stored in the node
    Node* Right;    // Pointer to right child (greater values)
    Node* Left;     // Pointer to left child (smaller values)
};

Node* Root = nullptr;   // Global root pointer, initially null

// Recursive function to insert a value into BST
Node* CreateNode(Node* Root, int value)
{
    if (Root == nullptr)  // If current subtree is empty
    {
        // Create a new node dynamically
        Node* NewNode = new Node;
        NewNode->Data  = value;      // Assign value
        NewNode->Right = nullptr;    // No right child yet
        NewNode->Left  = nullptr;    // No left child yet
        return NewNode;              // Return the new node
    }
    else  // Current node exists
    {
        if (value < Root->Data)      // Value belongs to left subtree
        {
            // Recursively insert into left child and update left pointer
            Root->Left  = CreateNode(Root->Left,  value);
        }
        else                         // Value belongs to right subtree (≥)
        {
            // Recursively insert into right child and update right pointer
            Root->Right = CreateNode(Root->Right, value);
        }
        return Root;                 // Return unchanged root
    }
}

// Wrapper function for insertion
void Insert(int value)
{
    Root = CreateNode(Root, value);  // Start insertion from root
}

// Preorder traversal: Root → Left → Right
void Preorder(Node* Root) // root -> left -> right
{
    if (Root == nullptr)   // Base case: empty subtree
    {
        return;            // Nothing to do
    }
    else
    {
        cout << Root->Data << " ";   // Visit root first
        Preorder(Root->Left);        // Then traverse left subtree
        Preorder(Root->Right);       // Finally traverse right subtree
    }
}

// Wrapper for Preorder
void PrintPreorder()                         // Wrapper
{
    if (Root == nullptr)                     // Check if tree is empty
    {
        cout << "BST is empty!" << endl;     // Inform user
    }
    else
    {
        Preorder(Root);                      // Start traversal from root
    }
}

// Inorder traversal: Left → Root → Right (gives sorted order)
void Inorder(Node* Root) // left -> root -> right
{
    if (Root == nullptr)   // Base case
    {
        return;
    }
    else
    {
        Inorder(Root->Left);                 // First traverse left subtree
        cout << Root->Data << " ";           // Then visit root
        Inorder(Root->Right);                // Finally traverse right subtree
    }
}

// Wrapper for Inorder
void PrintInorder()                         // Wrapper
{
    if (Root == nullptr)
        cout << "BST is empty!" << endl;
    else
        Inorder(Root);
}

// Postorder traversal: Left → Right → Root
void Postorder(Node* Root) // left -> right -> root
{
    if (Root == nullptr)
    {
        return;
    }
    else
    {
        Postorder(Root->Left);               // First traverse left subtree
        Postorder(Root->Right);              // Then traverse right subtree
        cout << Root->Data << " ";           // Finally visit root
    }
}

// Wrapper for Postorder
void PrintPostorder()                         // Wrapper
{
    if (Root == nullptr)
        cout << "BST is empty!" << endl;
    else
        Postorder(Root);
}

// Recursive search for a value
bool SearchNode(Node* Root, int value)
{
    if (Root == nullptr)                     // Reached empty node
    {
        return false;                       
    }
    else
    {
        if (value == Root->Data)             // Value found at current node
        {
            return true;                        
        }
        else if (value < Root->Data)         // Search left subtree
        {
            return SearchNode(Root->Left, value);  
        }
        else                                 // Search right subtree
        {
            return SearchNode(Root->Right, value); 
        }
    }
}

// Wrapper for search
void Search(int value)
{
    if (Root == nullptr)                     // Tree empty
    {
        cout << "BST is empty!" << endl;
    }
    else if (SearchNode(Root, value))        // Value exists
    {
        cout << value << " is found" << endl;
    }
    else                                     // Value not found
    {
        cout << value << " is not found" << endl;
    }
}

// Find node with minimum value (leftmost node)
Node* MinimumNode(Node* Root)
{
    if (Root == nullptr)                     // Empty subtree
    {
        return nullptr;
    }
    else
    {
        if (Root->Left == nullptr)           // No left child → this is the minimum
        {
            return Root;
        }
        else                                 // Keep going left
        {
            return MinimumNode(Root->Left);
        }
    }
}

// Wrapper for minimum
void Min()
{
    if (Root == nullptr)
    {
        cout << "BST is empty!" << endl;
    }
    else
    {
        cout << "the minimum node is " << MinimumNode(Root)->Data << endl;
    }
}

// Find node with maximum value (rightmost node)
Node* MaximumNode(Node* Root)
{
    if (Root == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (Root->Right == nullptr)          // No right child → this is the maximum
        {
            return Root;
        }
        else                                 // Keep going right
        {
            return MaximumNode(Root->Right);
        }
    }
}

// Wrapper for maximum
void Max()
{
    if (Root == nullptr)
    {
        cout << "BST is empty!" << endl;
    }
    else
    {
    cout << "the Maximum node is " << MaximumNode(Root)->Data << endl;
    }
}

// Recursive deletion of a node with given value
Node* DeleteNode(Node* Root, int value)
{
    if (Root == nullptr)                     // Value not found
    {
        return nullptr;
    }
    else if (value != Root->Data)            // Still searching
    {
        if (value < Root->Data)              // Go left
        {
            Root->Left  = DeleteNode(Root->Left,  value);  
        }
        else                                 // Go right
        {
            Root->Right = DeleteNode(Root->Right, value);  
        }
    }
    else  // Node to delete found
    {
        // Case 1: Leaf node (no children)
        if(Root->Left == nullptr && Root->Right == nullptr)
        {
            delete Root;                     // Free memory
            Root = nullptr;                  // Set to null
        }
        // Case 2: Only left child exists
        else if(Root->Left != nullptr && Root->Right == nullptr)
        {
            Root->Data = Root->Left->Data;   // Copy left child's data
            delete Root->Left;               // Delete left child
            Root->Left = nullptr;            // Set left pointer to null
        }
        // Case 3: Only right child exists
        else if(Root->Left == nullptr && Root->Right != nullptr)
        {
            Root->Data = Root->Right->Data;  // Copy right child's data
            delete Root->Right;              // Delete right child
            Root->Right = nullptr;           // Set right pointer to null
        }
        // Case 4: Two children
        else
        {
            // Find inorder predecessor (maximum in left subtree)
            Node* pre = MaximumNode(Root->Left);
            // Replace current node's value with predecessor's value
            Root->Data = pre->Data;                         
            // Delete the predecessor node from left subtree
            Root->Left = DeleteNode(Root->Left, pre->Data);
        }
    }
    return Root;  // Return possibly updated root
}

// Wrapper for deletion
void Delete(int value)
{
    Root = DeleteNode(Root, value);
}

int main()
{
    // Insert sample values to build BST
    Insert(15);
    Insert(13);
    Insert(30);
    Insert(19);
    Insert(7);
    Insert(99);

    // Display root and traversals
    cout << "The value of root in BTS is: " << Root->Data << endl;  // Note: typo "BTS"
    cout << "Preorder  : "; PrintPreorder();  cout << endl;
    cout << "Inorder   : "; PrintInorder();   cout << endl;
    cout << "Postorder : "; PrintPostorder(); cout << endl;

    Search(50);   // Search for value 50 (not present)
    Min();        // Print minimum value
    Max();        // Print maximum value

    Delete(30);   // Delete node with value 30

    return 0;     // Program ends (memory cleanup not shown for brevity)
}