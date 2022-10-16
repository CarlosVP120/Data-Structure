#include <iostream>
#include <queue>

using namespace std;

// A binary search tree is a binary tree in wich every node fits a specific ordering property
// all left descendents <= n < all right

struct Node
{
    int data;           // data of the node
    Node *left, *right; // right child

    Node(int d)
    {
        data = d;
        left = right = NULL;
    } // constructor for Node class
};

class BST
{
private:
    Node *Root; // root of the tree is the first element of the tree

    // Recursive fucntions to call privately from public functions to avoid code duplication and to make the code more readable and maintainable
    // These functions are private because they are only used by the public functions and not by the user

    void Insert(int &, Node *&); // Insert a node in BST     // O(log n)
    void InOrder(Node *);        // Print BST in InOrder     // O(n)
    void PreOrder(Node *);       // Print BST in PreOrder    // O(n)
    void PostOrder(Node *);      // Print BST in PostOrder   // O(n)
    void LevelByLevel(Node *);   // Print BST level by level // O(n)
    void DeleteNode(int &, Node *&);
    int height(Node *);

public:
    BST() : Root(NULL){}; // Constructor to initialize Root to NULL, NULL is a pointer to nothing and is used to indicate that the node is empty or does not exist in the tree

    ~BST() // Destructor to free the memory allocated to the tree
    {
        DeleteBST(Root);
        cout << "\nDestructor: BST deleted\n";
    }

    // Functions to call the recursive functions (non-recursive)
    void Insert(int &value) { Insert(value, Root); } // Insert a node in BST    // O(log n)
    void InOrder() { InOrder(Root); }                // Print BST in InOrder    // O(n)
    void PreOrder() { PreOrder(Root); }              // Print BST in PreOrder   // O(n)
    void PostOrder() { PostOrder(Root); }            // Print BST in PostOrder  // O(n)
    void LevelByLevel() { LevelByLevel(Root); }      // Print BST level by level// O(n)
    void BFT();                                      // Print BST in Breadth First Traversal // O(n)

    void SubstituteToMin(Node *&, Node *&);                  // Substitute a node with the minimum value in the right subtree,
    void DeleteNode(int &value) { DeleteNode(value, Root); } // Delete a node from BST
    void visit(int);
    void DeleteBST(Node *&); // Delete the BST         // O(n) (worst case) or O(log n) (best case) or O(n) (average case)
    int height() { return height(Root); }
};

void BST::Insert(int &value, Node *&root) // We use reference to avoid copying the value, if you modified the value in the function it also modified out of the function
{
    if (root == NULL)
    {
        root = new Node(value);
    }

    else
    {
        if (value < root->data) // if value is less than the data of the root, go to the left
        {
            Insert(value, root->left); // recursive call to insert the value in the left subtree of the root
        }

        else if (value > root->data) // if value is greater than the data of the root, go to the right
        {
            Insert(value, root->right); // recursive call to insert the value in the right subtree of the root
        }

        else // if value is equal to the data of the root, do nothing
        {
            cout << "Repeated element\n";
        }
    }
}

int BST::height(Node *root)
{
    if (root == NULL)
        return -1;
    else
    {
        int left_side = height(root->left);
        int right_side = height(root->right);

        return max(left_side, right_side) + 1;
    }
}

// The PreOrder function is generally a recursive function as well and moves through the leves of the tree in the following order: root, left, right
//    A
// B     C                       PreOrder: A B C
void BST::PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// The InOrder function is generally a recursive function as well and moves through the leves of the tree in the following order: left, root, right
//    B
// A     C                       InOrder: A B C
void BST::InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// The PostOrder function is generally a recursive function as well and moves through the leves of the tree in the following order: left, right, root
//    C
// A     B                       PostOrder: A B C
void BST::PostOrder(Node *root) // print the brothers of the root first
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

// The LevelByLevel function is generally a recursive function as well and moves through the leves of the tree in the following order: root, left, right
//    A
// B     C                       LevelByLevel: A B C
void BST::LevelByLevel(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> Q; // queue to store the nodes of the tree
    Q.push(root);    // push the root of the tree in the queue

    while (!Q.empty()) // while the queue is not empty
    {
        Node *current = Q.front(); // get the first element of the queue
        Q.pop();                   // remove the first element of the queue

        cout << current->data << " "; // print the data of the current node

        if (current->left != NULL) // if the left child of the current node is not NULL
        {
            Q.push(current->left); // push the left child of the current node in the queue
        }

        if (current->right != NULL) // if the right child of the current node is not NULL
        {
            Q.push(current->right); // push the right child of the current node in the queue
        }
    }
}

// The Breadth First Traversal function is generally a non-recursive function and moves through the leves of the tree in the following order: root, left, right
void BST::BFT()
{
    if (Root == NULL)
    {
        cout << "The BST is empty" << endl;
        return;
    }

    queue<Node *> Q; // queue to store the nodes of the tree
    Q.push(Root);    // push the root of the tree in the queue

    Node *Aux; // Auxiliar pointer to store the nodes of the tree
    while (!Q.empty())
    {
        Q.push(NULL);

        Aux = Q.front(); // get the first element of the queue

        while (Aux != NULL)
        {
            cout << Aux->data << " "; // print the data of the node

            if (Aux->left != NULL) // if the left child of the node is not NULL, push it in the queue
            {
                Q.push(Aux->left);
            }

            if (Aux->right != NULL) // if the right child of the node is not NULL, push it in the queue
            {
                Q.push(Aux->right);
            }

            Q.pop();         // pop the first element of the queue
            Aux = Q.front(); // get the first element of the queue
        }
        Q.pop(); // pop the first element of the queue

        cout << endl;
    }
}

// Delete a node from BST (Binary Search Tree)
// There are 3 cases to delete a node from BST:
// 1. The node is a leaf (has no children) -> delete the node and set the pointer to NULL
// 2. The node has one child -> delete the node and set the pointer to the child of the node
// 3. The node has two children (we substitute the node with the minimum value in the right subtree)

// Substitute a node with the minimum value in the right subtree
void BST::SubstituteToMin(Node *&root, Node *&apAux)
{
    if (root->left != NULL)
    {
        SubstituteToMin(root->left, apAux);
    }
    else
    {
        // Transfer the data from the substitute node
        apAux->data = root->data;

        // Save the minValue-right subtree (To delete)
        apAux = root;

        // Swap place minValue-right subtree with right subtree
        root = root->right;
    }
}

// Delete a node from BST (Binary Search Tree)
void BST::DeleteNode(int &value, Node *&root)
{
    if (root == NULL)
    {
        cout << "The BST is empty" << endl;
        return;
    }

    if (value < root->data) // if value is less than the data of the root, go to the left
    {
        DeleteNode(value, root->left); // recursive call to delete the value in the left subtree of the root
    }

    else if (value > root->data) // if value is greater than the data of the root, go to the right
    {
        DeleteNode(value, root->right); // recursive call to delete the value in the right subtree of the root
    }

    else // if value is equal to the data of the root, delete the node
    {
        Node *apAux = root; // Auxiliar pointer to store the node to delete

        if (root->left == NULL) // if the left child of the node is NULL
        {
            root = root->right; // set the pointer to the right child of the node
        }

        else if (root->right == NULL) // if the right child of the node is NULL
        {
            root = root->left; // set the pointer to the left child of the node
        }

        else // if the node has two children
        {
            SubstituteToMin(root->right, apAux); // substitute the node with the minimum value in the right subtree
        }

        delete apAux; // delete the node
        cout << "\nNode to delete: " << value << endl;
        cout << "The node " << value << " was deleted" << endl;
    }
}

void BST::DeleteBST(Node *&root)
{
    if (root != NULL)
    {
        DeleteBST(root->left);
        DeleteBST(root->right);
        delete root;
    }
}

void BST::visit(int value)
{
    if (value == 1)
    {
        cout << "PreOrder: ";
        PreOrder(Root);
    }
    else if (value == 2)
    {
        cout << "InOrder: ";
        InOrder(Root);
    }
    else if (value == 3)
    {
        cout << "PostOrder: ";
        PostOrder(Root);
    }
    else if (value == 4)
    {
        cout << "LevelByLevel: ";
        LevelByLevel(Root);
    }
    else
    {
        cout << "Invalid option" << endl;
    }
}

int main()
{
    system("cls");
    BST A;

    vector<int> v = {47, 60, 22, 12, 6, 13, 41, 20, 52, 16};
    for (int i : v)
    {
        A.Insert(i);
    }

    cout << "height: " << A.height() << endl;

    // VISIT
    int option;
    cout << "Choose the way to visit the BST: " << endl;
    cout << "1. PreOrder" << endl;
    cout << "2. InOrder" << endl;
    cout << "3. PostOrder" << endl;
    cout << "4. LevelByLevel" << endl;
    cout << "Option: ";
    cin >> option;
    cout << endl;

    A.visit(option);
    cout << endl;

    A.BFT();
    // cout << "The height of the BST is: " << A.height() << endl;

    int a = 16; // leaf node
    A.DeleteNode(a);

    A.BFT();
    cout << "The height of the BST is: " << A.height() << endl;

    a = 13; // node with one child
    A.DeleteNode(a);

    A.BFT();
    cout << "The height of the BST is: " << A.height() << endl;

    a = 47; // node with two children
    A.DeleteNode(a);

    A.BFT();
    cout << "The height of the BST is: " << A.height() << endl;

    return 0;
}
