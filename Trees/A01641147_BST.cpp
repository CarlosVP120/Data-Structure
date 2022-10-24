#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

// Carlos Alberto Veryan Peña A01641147

struct Node
{
    long long data;
    Node *left, *right;

    Node(long long d)
    {
        data = d;
        left = right = NULL;
    }
};

class BST
{
private:
    Node *Root;

    void Insert(long long &, Node *&);     // O(log n)
    void InOrder(Node *);            // O(n)
    void PreOrder(Node *);           // O(n)
    void PostOrder(Node *);          // O(n)
    void LevelByLevel(Node *);       // O(n)
    void DeleteNode(int &, Node *&); // O(log n)
    int height(Node *);              // O(n)
    void ancestors(Node *, int);     // O(log n)
    int Level(Node *, int);          // O(n)

public:
    BST() : Root(NULL){};

    ~BST()
    {
        cout << "Deleting the tree..." << endl;
        DeleteBST(Root);
        cout << "\nDestructor: BST deleted\n";
    }
    // insert long long
    void Insert(long long &value) {Insert(value, Root); } // Insert a node in the BST O(log n)
    void InOrder() { InOrder(Root); }                // Display the BST in InOrder O(n)
    void PreOrder() { PreOrder(Root); }              // Display the BST in PreOrder O(n)
    void PostOrder() { PostOrder(Root); }            // Display the BST in PostOrder O(n)
    void LevelByLevel() { LevelByLevel(Root); }      // Display the BST in LevelByLevel O(n)
    void BFT();                                      // Display the BST in LevelByLevel O(n)

    void SubstituteToMin(Node *&, Node *&);                  // Substitute a node with the minimum value in the right subtree. O(log n)
    void DeleteNode(int &value) { DeleteNode(value, Root); } // Delete a node from BST // O(log n)
    void visit(int);                                         // Select an order to print the tree // O(n)
    void DeleteBST(Node *&);                                 // Delete the BST // O(n)
    int height() { return height(Root); }                    // Height of the tree // O(n)
    void ancestors(int value) { ancestors(Root, value); }    // Print ancestors of a node // O(log n)
    int Level(int value) { return Level(Root, value); }      // Returns the level of a node in a tree // O(n)
};

/*1. First of all, we check if the root is NULL. If it is, we create a new node with the value we want to insert.
2. If the root is not NULL, we check if the value we want to insert is less than the value of the root. If it is, we call Insert() again, passing the value we want to insert and the root->left as parameters.
3. If the value we want to insert is greater than the value of the root, we call Insert() again, passing the value we want to insert and the root->right as parameters.
4. If the value we want to insert is equal to the value of the root, we print on the screen "Repeated element".*/

void BST::Insert(long long &value, Node *&root)
{
    if (root == NULL)
    {
        root = new Node(value);
    }

    else
    {
        if (value < root->data)
        {
            Insert(value, root->left);
        }

        else if (value > root->data)
        {
            Insert(value, root->right);
        }

        else
        {
            cout << "Repeated element\n";
        }
    }
}

/*1. We first check to see if the current node is NULL or not. If it is NULL, we return -1. If it is not NULL, we continue on to step 2.
2. We get the height of the left side of the tree by calling the height method on the left child of the current node. We then do the same thing for the right side of the tree by calling the height method on the right child of the current node.
3. We then return the maximum of the height of the left and right side of the tree, plus 1. The plus 1 is to account for the current node.*/

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

/* 1. If the root is NULL, then there is nothing to print, so return.
 2. Print the data at the root.
 3. Recursively call PreOrder on the left subtree.
 4. Recursively call PreOrder on the right subtree. */

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

/* 1. If the root of the tree is NULL, then we return from the function.
 2. We call the InOrder function recursively for the left subtree.
 3. We print the data of the root node.
 4. We call the InOrder function recursively for the right subtree.*/

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

/* Here is the explanation for the code above:
1. The function is called PostOrder and it takes a Node pointer as a parameter, which represents the root of the tree. The function does not return anything.
2. The function checks if the root is NULL, if so, it returns to the caller.
3. The function calls itself with the left child of the root as the parameter, this will print the left subtree in postorder.
4. The function calls itself with the right child of the root as the parameter, this will print the right subtree in postorder.
5. The function prints the data stored in the root node. */

void BST::PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

/* 1. The function starts with the declaration of a queue of Node pointers named Q.  Q is a queue of Nodes, and each Node pointer will point to the address of a Node in the binary search tree.
2.  If the root is NULL, the function returns.  Otherwise, the root is pushed onto the queue.
3.  The while loop checks if the queue is empty.  If the queue is not empty, the node at the front of the queue is stored in a Node pointer named current.  The front of the queue is then popped.
4.  The data stored in the node to which current points is printed.
5.  If the left child of the node to which current points is not NULL, the left child is pushed onto the queue.
6.  If the right child of the node to which current points is not NULL, the right child is pushed onto the queue.
7.  This process continues until the queue is empty. */

void BST::LevelByLevel(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *current = Q.front();
        Q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
        {
            Q.push(current->left);
        }

        if (current->right != NULL)
        {
            Q.push(current->right);
        }
    }
}

/*1. The first step is to check if the tree is empty. If it is, then we return from the function. If not, we move to the next step.
2. Then we will create the queue Q and push the root of the tree into it.
3. Then we will create a pointer called Aux that will hold the nodes from the queue. We will use a while loop to traverse through the queue. The loop will continue until the queue is empty. (Remember that we are using a queue to implement the BFS algorithm.)
4. Inside the while loop, we will push NULL into the queue. This is to mark the end of each level.
5. We will assign the front of the queue to Aux. Then we will use another while loop to traverse through the nodes in the queue. The loop will continue until we reach the NULL which we pushed in the previous step.
6. Inside the while loop, we will print the value of the node pointed by Aux. Then, we will check if the left child of Aux exists. If it does, we will push it into the queue. We will do the same for the right child.
7. Then we will pop the node from the queue and assign the front of the queue to Aux.
8. The outer while loop will continue until the queue is empty. */

void BST::BFT()
{
    if (Root == NULL)
    {
        cout << "The BST is empty" << endl;
        return;
    }

    queue<Node *> Q;
    Q.push(Root);

    Node *Aux;
    while (!Q.empty())
    {
        Q.push(NULL);

        Aux = Q.front();

        while (Aux != NULL)
        {
            cout << Aux->data << " ";

            if (Aux->left != NULL)
            {
                Q.push(Aux->left);
            }

            if (Aux->right != NULL)
            {
                Q.push(Aux->right);
            }

            Q.pop();
            Aux = Q.front();
        }
        Q.pop();

        cout << endl;
    }
}

/* 1. We are using a pointer to a pointer (Node *&root) to be able to modify the root of the tree.
2. We are using a pointer to a pointer (Node *&apAux) to be able to modify the node we want to substitute.
3. We are using a pointer to a pointer (root->left) because we are modifying the left node of the root.
4. We are using a pointer to a pointer (root->right) because we are modifying the right node of the root.
5. We are using a pointer to a pointer (apAux->data) to be able to modify the data of the node we want to substitute.
6. We are using a pointer to a pointer (apAux) to be able to modify the node we want to substitute. */

void BST::SubstituteToMin(Node *&root, Node *&apAux)
{
    if (root->left != NULL)
    {
        SubstituteToMin(root->left, apAux);
    }
    else
    {
        apAux->data = root->data;

        apAux = root;

        root = root->right;
    }
}

/* 1. If the root is NULL, it means that the BST is empty.
2. If the value is less than the value of the root, it means that the value to delete is in the left subtree.
3. If the value is greater than the value of the root, it means that the value to delete is in the right subtree.
4. If the value is equal to the value of the root, we found the node to delete.
5. If the root has only one child, the root will be replaced with the child.
6. If the root has two children, we will replace the root with the minimum value of the right subtree.
7. If the root has no children, we will delete the root. */

void BST::DeleteNode(int &value, Node *&root)
{
    if (root == NULL)
    {
        cout << "The BST is empty" << endl;
        return;
    }

    if (value < root->data)
    {
        DeleteNode(value, root->left);
    }

    else if (value > root->data)
    {
        DeleteNode(value, root->right);
    }

    else
    {
        Node *apAux = root;

        if (root->left == NULL)
        {
            root = root->right;
        }

        else if (root->right == NULL)
        {
            root = root->left;
        }

        else
        {
            SubstituteToMin(root->right, apAux);
        }

        delete apAux;
        cout << "\nNode to delete: " << value << endl;
        cout << "The node " << value << " was deleted" << endl;
    }
}

/* 1. If the root is not NULL, then delete the left subtree, the right subtree, and the root.
2. Set the root to NULL. */

void BST::DeleteBST(Node *&root)
{
    if (root != NULL)
    {
        cout << "Deleting " << root->data << endl;
        DeleteBST(root->left);
        DeleteBST(root->right);
        delete root;
        root = NULL;
    }
}

/* 1. The visit function is the only function that is not private, the reason for this is because it is the main function that the user will be calling.
2. The visit function takes in 1 parameter, which is the option the user would like to see.
3. If the option is 1, then the PreOrder function is called.
4. If the option is 2, then the InOrder function is called.
5. If the option is 3, then the PostOrder function is called.
6. If the option is 4, then the LevelByLevel function is called.
7. If the option is not 1, 2, 3, or 4, then the option is invalid and the user is informed.*/

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

/*1. If the root is NULL, then the value is not present in the tree and return 0.
2. If the root's data is equal to the value, then return 1.
3. Check the left subtree for the value, if it is found, then return the level + 1.
4. Check the right subtree for the value, if it is found, then return the level + 1.
5. If the value is not found in the tree, then return 0. */

int BST::Level(Node *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == value)
    {
        return 1;
    }

    int level = Level(root->left, value);

    if (level != 0)
    {
        return level + 1;
    }

    level = Level(root->right, value);

    if (level != 0)
    {
        return level + 1;
    }

    return 0;
}

/* 1. If the tree is empty or the value is equal to the root's data, we return because we have reached our destination.
2. If the value is less than the root's data, we print the root's data and call the function recursively for the left subtree.
3. If the value is greater than the root's data, we print the root's data and call the function recursively for the right subtree. */

void BST::ancestors(Node *root, int value)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == value)
    {
        return;
    }

    if (root->data > value)
    {
        cout << root->data << " ";
        ancestors(root->left, value);
    }

    else if (root->data < value)
    {
        cout << root->data << " ";
        ancestors(root->right, value);
    }
}

long long ipToInt(string ip)
{ // O(n)
    string iPstr = "";
    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] == '.')
        {
            // Do nothing
        }
        else
        {
            iPstr += ip[i];
        }
    }
    // cout << stoll(iPstr) << endl;
    return stoll(iPstr);
}

string getIP(string line)
{ // O(n)
    string ip = "";
    string finalIP = "";
    for (int i = 16; i < line.length(); i++)
    { // O(n)
        if (line[i] == ':')
        {
            break;
        }
        ip += line[i];
    }

    // Divide the IP in 4 strings
    string ip1 = "";
    string ip2 = "";
    string ip3 = "";
    string ip4 = "";
    int count = 0;
    for (int i = 0; i < ip.length(); i++)
    { // O(n)
        if (ip[i] == '.')
        {
            count++;
        }
        else
        {
            if (count == 0)
            {
                ip1 += ip[i];
            }
            else if (count == 1)
            {
                ip2 += ip[i];
            }
            else if (count == 2)
            {
                ip3 += ip[i];
            }
            else if (count == 3)
            {
                ip4 += ip[i];
            }
        }
    }

    vector<string> iPs = {ip1, ip2, ip3, ip4};
    // add zeros so that each part has 3 values
    for (int i = 0; i < iPs.size(); i++)
    {
        while (iPs[i].length() < 3)
        {
            iPs[i] = "0" + iPs[i];
        }
    }

    return iPs[0] + "." + iPs[1] + "." + iPs[2] + "." + iPs[3];
}

int main()
{
    BST Tree;

    // Save all the lines in a vector
    ifstream file("Bitacora.txt");
    string line;
    vector<string> lines;
    while (getline(file, line))
    {
        if (line[4] >= '0' && line[4] <= '9' && line[5] == ' ')
        {
            line.insert(4, "0");
        }
        lines.push_back(line);
    }
    file.close();

    // Save the IPs in the tree
    for (int i = 0; i < lines.size(); i++)
    {
        string ip = getIP(lines[i]);
        long long ipInt = ipToInt(ip);
        cout << ipInt << endl;
        Tree.Insert(ipInt);
    }

    //print the lines
    for (int i = 0; i < lines.size(); i++)
    {
        cout << ipToInt(getIP(lines[i])) << endl;
    }

    return 0;
}
