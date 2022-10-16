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

    void Insert(int &, Node *&);     // Insert a node in BST     // O(log n)
    void InOrder(Node *);            // Print BST in InOrder     // O(n)
    void PreOrder(Node *);           // Print BST in PreOrder    // O(n)
    void PostOrder(Node *);          // Print BST in PostOrder   // O(n)
    void LevelByLevel(Node *);       // Print BST level by level // O(n)
    void DeleteNode(int &, Node *&); // Delete a node from BST // O(log n)
    int height(Node *);              // Height of the tree      // O(n)
    void ancestors(Node *, int);     // Print ancestors of a node // O(log n)
    int Level(Node *, int);          // Returns the level of a node in a tree // O(n)

public:
    BST() : Root(NULL){}; // Constructor to initialize Root to NULL, NULL is a pointer to nothing and is used to indicate that the node is empty or does not exist in the tree

    ~BST() // Destructor to free the memory allocated to the tree
    {
        cout << "Deleting the tree..." << endl;
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
    void DeleteNode(int &value) { DeleteNode(value, Root); } // Delete a node from BST // O(log n)
    void visit(int);                                         // Select an order to print the tree // O(n)
    void DeleteBST(Node *&);                                 // Delete the BST // O(n)
    int height() { return height(Root); }                    // Height of the tree // O(n)
    void ancestors(int value) { ancestors(Root, value); }    // Print ancestors of a node // O(log n)
    int Level(int value) { return Level(Root, value); }      // Returns the level of a node in a tree // O(n)
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

int BST::height(Node *root) // Compares the height of the left and right subtrees and returns the maximum height
{
    if (root == NULL) // if the tree is empty, return 0
        return -1;
    else
    {
        int left_side = height(root->left);   // height of the left subtree
        int right_side = height(root->right); // height of the right subtree

        return max(left_side, right_side) + 1; // return the maximum height + 1
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
    if (root == NULL) // if the tree is empty, end the function
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
    if (root == NULL) // if the tree is empty, end the function
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
    if (root != NULL) // if the tree is not empty
    {
        cout << "Deleting " << root->data << endl;
        DeleteBST(root->left);  // delete the left subtree
        DeleteBST(root->right); // delete the right subtree
        delete root;            // delete the root
        root = NULL;            // set the root to NULL
    }
}

void BST::visit(int value) // Decide the way you want to order the tree
{
    if (value == 1)
    {
        cout << "PreOrder: "; // print the data of the root first
        PreOrder(Root);
    }
    else if (value == 2)
    {
        cout << "InOrder: "; // print the data of the root in the middle
        InOrder(Root);
    }
    else if (value == 3)
    {
        cout << "PostOrder: "; // print the data of the root last
        PostOrder(Root);
    }
    else if (value == 4)
    {
        cout << "LevelByLevel: "; // print the data of the root in the same level
        LevelByLevel(Root);
    }
    else
    {
        cout << "Invalid option" << endl; // if the option is invalid, print an error message
    }
}

int BST::Level(Node *root, int value) // return the level of a node
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == value) // if the data of the root is equal to the value, return 1
    {
        return 1;
    }

    int level = Level(root->left, value); // get the level of the left subtree

    if (level != 0) // if the level is not 0, return the level + 1
    {
        return level + 1;
    }

    level = Level(root->right, value); // get the level of the right subtree

    if (level != 0) // if the level is not 0, return the level + 1
    {
        return level + 1;
    }

    return 0;
}

void BST::ancestors(Node *root, int value) // print the ancestors of a node
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == value) // if the data of the root is equal to the value, return
    {
        return;
    }

    if (root->data > value) // if the data of the root is greater than the value, go to the left
    {
        cout << root->data << " ";    // print the data of the root
        ancestors(root->left, value); // recursive call to print the ancestors of the left subtree of the root
    }

    else if (root->data < value) // if the data of the root is less than the value, go to the right
    {
        cout << root->data << " ";     // print the data of the root
        ancestors(root->right, value); // recursive call to print the ancestors of the right subtree of the root
    }
}

int main()
{
    BST A;

    vector<int> v = {47, 60, 22, 12, 6, 13, 41, 20, 52, 16};
    for (int i : v)
    {
        A.Insert(i);
    }

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
    cout << endl
         << endl;

    A.BFT();
    cout << "The height of the BST is: " << A.height() << endl;

    // ANCESTORS
    int value;
    cout << endl
         << "Enter the value to find the ancestors: ";
    cin >> value;
    cout << "The ancestors of " << value << " are: ";
    A.ancestors(value);
    cout << endl;

    // WHAT LEVEL AM I
    cout << endl
         << "Enter the value to find the level: ";
    cin >> value;
    cout << "The level of " << value << " is: " << A.Level(value) << endl;

    // DELETE NODE
    vector<int> toDelete = {16, 13, 47, 20};
    int a;

    for (int i = 0; i < toDelete.size(); i++)
    {
        a = toDelete[i]; // leaf node
        A.DeleteNode(a);
        cout << endl;

        A.BFT();
        cout << "The height of the BST is: " << A.height() << endl;
    }
    cout << endl;

    return 0;
}
