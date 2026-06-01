#include<iostream>
using namespace std;

// Node structure for Binary Search Tree (BST)
// BST Rules:
// - Left subtree contains values LESS than node
// - Right subtree contains values GREATER OR EQUAL than node
struct Node {
    int Data;       // Value stored in the node (represents key in BST)
    Node* Right;    // Pointer to right child (greater or equal values)
    Node* Left;     // Pointer to left child (smaller values)
};

Node* Root = nullptr;   // Global root pointer, initially null (tree is empty)

// INSERTION (Recursive BST Insert)
Node* CreateNode(Node* Root, int value)
{
    if (Root == nullptr)  // Base case: empty position found → create node
    {
        // Allocate memory for new node
        Node* NewNode = new Node;

        NewNode->Data  = value;      // Store value in node
        NewNode->Right = nullptr;    // Initialize right child
        NewNode->Left  = nullptr;    // Initialize left child

        return NewNode;              // Return newly created node
    }
    else  // Traverse tree to find correct insertion position
    {
        if (value < Root->Data)      // If value is smaller → go left
        {
            Root->Left  = CreateNode(Root->Left,  value);
        }
        else                         // If value is greater or equal → go right
        {
            Root->Right = CreateNode(Root->Right, value);
        }

        return Root; // Return unchanged root after insertion
    }
}

// Wrapper function for insertion (starts from global Root)
void Insert(int value)
{
    Root = CreateNode(Root, value);
}

// PREORDER TRAVERSAL (Root → Left → Right)
void Preorder(Node* Root) // DFS traversal (Root first)
{
    if (Root == nullptr)   // Base case: stop at null node
    {
        return;
    }
    else
    {
        cout << Root->Data << " ";   // Visit current node
        Preorder(Root->Left);        // Traverse left subtree
        Preorder(Root->Right);       // Traverse right subtree
    }
}

// Wrapper for Preorder traversal
void PrintPreorder()
{
    if (Root == nullptr)
    {
        cout << "BST is empty!" << endl;
    }
    else
    {
        Preorder(Root);
    }
}

// INORDER TRAVERSAL (Left → Root → Right)
// IMPORTANT: In BST → prints sorted order
void Inorder(Node* Root)
{
    if (Root == nullptr)
    {
        return;
    }
    else
    {
        Inorder(Root->Left);         // Visit left subtree first
        cout << Root->Data << " ";   // Visit node
        Inorder(Root->Right);        // Visit right subtree
    }
}

// Wrapper for Inorder traversal
void PrintInorder()
{
    if (Root == nullptr)
    {
        cout << "BST is empty!" << endl;
    }
    else
    {
        Inorder(Root);
    }
}

// POSTORDER TRAVERSAL (Left → Right → Root)
void Postorder(Node* Root)
{
    if (Root == nullptr)
    {
        return;
    }
    else
    {
        Postorder(Root->Left);       // Visit left subtree
        Postorder(Root->Right);      // Visit right subtree
        cout << Root->Data << " ";   // Visit root last
    }
}

// Wrapper for Postorder traversal
void PrintPostorder()
{
    if (Root == nullptr)
    {
        cout << "BST is empty!" << endl;
    }
    else
    {
        Postorder(Root);
    }
}

// SEARCH OPERATION (BST Search)
bool SearchNode(Node* Root, int value)
{
    if (Root == nullptr)   // Base case: not found
    {
        return false;
    }
    else
    {
        if (value == Root->Data)         // Found value
        {
            return true;
        }
        else if (value < Root->Data)     // Search left
        {
            return SearchNode(Root->Left, value);
        }
        else                             // Search right
        {
            return SearchNode(Root->Right, value);
        }
    }
}

// Wrapper for search
void Search(int value)
{
    if (Root == nullptr)
    {
        cout << "BST is empty!" << endl;
    }
    else if (SearchNode(Root, value))
    {
        cout << value << " is found" << endl;
    }
    else
    {
        cout << value << " is not found" << endl;
    }
}

// MINIMUM VALUE (Leftmost node)
Node* MinimumNode(Node* Root)
{
    if (Root == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (Root->Left == nullptr)
        {
            return Root;
        }
        else
        {
            return MinimumNode(Root->Left);
        }
    }
}

// Wrapper
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

// MAXIMUM VALUE (Rightmost node)
Node* MaximumNode(Node* Root)
{
    if (Root == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (Root->Right == nullptr)
        {
            return Root;
        }
        else
        {
            return MaximumNode(Root->Right);
        }
    }
}

// Wrapper
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

// DELETE NODE (BST Deletion)
Node* DeleteNode(Node* Root, int value)
{
    if (Root == nullptr)
    {
        return nullptr;
    }
    else if (value != Root->Data)
    {
        if (value < Root->Data)
        {
            Root->Left  = DeleteNode(Root->Left,  value);
        }
        else
        {
            Root->Right = DeleteNode(Root->Right, value);
        }
    }
    else
    {
        // Case 1: Leaf node
        if(Root->Left == nullptr && Root->Right == nullptr)
        {
            delete Root;
            return nullptr;
        }
        // Case 2: Only left child
        else if(Root->Left != nullptr && Root->Right == nullptr)
        {
            Node* Temp = Root->Left;
            delete Root;
            return Temp;
        }
        // Case 3: Only right child
        else if(Root->Left == nullptr && Root->Right != nullptr)
        {
            Node* Temp = Root->Right;
            delete Root;
            return Temp;
        }
        // Case 4: Two children
        else
        {
            Node* pre = MaximumNode(Root->Left); // Inorder predecessor

            Root->Data = pre->Data;              // Replace value

            Root->Left = DeleteNode(Root->Left, pre->Data); // Delete predecessor
        }
    }
    return Root;
}

// Wrapper for deletion
void Delete(int value)
{
    if (Root == nullptr)
    {
        cout << "BST is empty!" << endl;
        return;
    }

    Root = DeleteNode(Root, value);
    cout << "Delete operation executed" << endl;
}

// COUNT NODES
int CountNodes(Node* Root)
{
    if(Root == nullptr)
    {
        return 0;
    }

    return 1 + CountNodes(Root->Left) + CountNodes(Root->Right);
}

// HEIGHT (Edges-based)
int HeightEdges(Node* Root)
{
    if (Root == nullptr)
    {
        return -1; // Height in edges definition
    }

    int leftH = HeightEdges(Root->Left);
    int rightH = HeightEdges(Root->Right);

    return 1 + max(leftH, rightH);
}

// Wrapper
void Height()
{
    cout << "Height is : " << HeightEdges(Root) << endl;
}

// BALANCE CHECK (AVL-style check)
int checkBalance(Node* Root)
{
    if (Root == nullptr)
    {
        return 0;
    }
    else
    {
        int left = checkBalance(Root->Left);
        if (left == -1)
        {
            return -1;
        }

        int right = checkBalance(Root->Right);
        if (right == -1)
        {
            return -1;
        }

        if (abs(left - right) > 1)
        {
            return -1;
        }

        return 1 + max(left, right);
    }
}

// Wrapper
void Balance()
{
    if(checkBalance(Root) == -1)
    {
        cout << "Tree isn't balanced" << endl;
    }
    else
    {
        cout << "Tree is balanced" << endl;
    }
}

// CLEAN TREE (Free memory safely)
void CleanTree(Node* Root)
{
    if (Root == nullptr)
    {
        return;
    }

    CleanTree(Root->Left);
    CleanTree(Root->Right);
    delete Root;
}

// Wrapper
void Clean()
{
    CleanTree(Root);
    Root = nullptr;
}

// MAIN FUNCTION
int main()
{
    cout << "Let's build a Binary Search Tree" << endl;

    cout << "How many element do you want for your BST ? " << endl;
    int size;
    cin >> size;

    if(size <= 0)
    {
        cout << "your size cannot less than or equal to zero!" << endl;
        return 1;
    }

    int value;

    // Get user input and insert each value into BST
    for(int i = 0; i < size; i++)
    {
        cout << "What's your value for element No. " << i + 1 << " ?" << endl;
        cin >> value;
        Insert(value);
    }

    // Display tree information
    cout << "Total elements is " << CountNodes(Root) << endl;
    cout << "The value of root in BST is: " << Root->Data << endl;

    // Display all three traversals
    cout << "Preorder  : "; PrintPreorder();  cout << endl;
    cout << "Inorder   : "; PrintInorder();   cout << endl;
    cout << "Postorder : "; PrintPostorder(); cout << endl;

    // Search for a value (50 – likely not present)
    Search(50);
    // Show min and max
    Min();
    Max();

    // Delete node with value 30
    Delete(30);

    // Show updated tree
    cout << "Total elements is " << CountNodes(Root) << endl;

    cout << "Preorder  : "; PrintPreorder();  cout << endl;
    cout << "Inorder   : "; PrintInorder();   cout << endl;
    cout << "Postorder : "; PrintPostorder(); cout << endl;

    Min();
    Max();

    // Additional metrics: height, balance, and cleanup
    Height();
    Balance();
    Clean();   // Free all memory before program ends

    return 0;
}
