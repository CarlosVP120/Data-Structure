#include<iostream>
#include<vector>
using namespace std;

// Carlos ALberto Veryan Peña A01641147

template <typename T> // T is the type of data stored in the tree
class AVL{
    public:
        class node{ // Node of the tree
            public:
                T key;
                int height;
                node * left;
                node * right;
                node(T k){ // Constructor
                    height = 1;
                    key = k;
                    left = NULL;
                    right = NULL;
                }
        };
        node * root = NULL; // Root of the tree
        int n; // Number of nodes in the tree
        void insert(T x){ // Insert a node with key x O(log n)
            root=insertUtil(root, x);
        }
        void remove(T x){ // Remove a node with key x O(log n)
            root=removeUtil(root, x);
        }

        bool search(T x){ // Search for a node with key x O(log n)
            return searchUtil(root, x);
        }

        void print(){ // Print the tree in order O(n)
            inorderUtil(root);
            cout<<endl;
        }

        void levelOrder(){ // Print the tree in level order O(n)
            int h = height(root);
            for(int i=1;i<=h;i++){
                printLevel(root, i);
                cout<<endl;
            }
        }

        int size(){ // Return the number of nodes in the tree O(1)
            return getSize(root);
        }


    private:

        bool searchUtil(node * r, T x){ // Search for a node with key x O(log n)
            if(r==NULL) return false;
            if(r->key==x) return true;
            if(r->key>x) return searchUtil(r->left, x);
            return searchUtil(r->right, x);
        }

        int getSize(node * n){ // Get the size of the tree O(1)
            if(n==NULL) return 0;
            return getSize(n->left)+getSize(n->right)+1;
        }

        int height(node * head){ // Return the height of the tree O(1)
            if(head==NULL) return 0;
            return head->height;
        }

        node * rightRotation(node * head){ // Right rotation O(1)
            node * newhead = head->left;
            head->left = newhead->right;
            newhead->right = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        node * leftRotation(node * head){ // Left rotation O(1)
            node * newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        void inorderUtil(node * head){ // Print the tree in inorder O(n)
            if(head==NULL) return ;
            inorderUtil(head->left);
            cout<<head->key<<" ";
            inorderUtil(head->right);
        }

        node * insertUtil(node * head, T x){ // Insert a node in the tree O(log n)
            if(head==NULL){
                n+=1;
                node * temp = new node(x);
                return temp;
            }
            if(x < head->key) head->left = insertUtil(head->left, x);
            else if(x > head->key) head->right = insertUtil(head->right, x);
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1){
                if(x < head->left->key){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal<-1){
                if(x > head->right->key){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }
        node * removeUtil(node * head, T x){ // Remove a node from the tree O(log n)
            if(head==NULL) return NULL; 
            if(x < head->key){
                head->left = removeUtil(head->left, x);
            }else if(x > head->key){
                head->right = removeUtil(head->right, x);
            }else{
                node * r = head->right;
                if(head->right==NULL){
                    node * l = head->left;
                    delete(head);
                    head = l;
                }else if(head->left==NULL){
                    delete(head);
                    head = r;
                }else{
                    while(r->left!=NULL) r = r->left;
                    head->key = r->key;
                    head->right = removeUtil(head->right, r->key);
                }
            }
            if(head==NULL) return head;
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1){
                if(height(head->left) >= height(head->right)){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal < -1){
                if(height(head->right) >= height(head->left)){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }

        void printLevel(node * head, int level){ // Print the tree in level order O(n)
            if(head==NULL) return;
            if(level==1){
                cout<<head->key<<" ";
            }else{
                printLevel(head->left, level-1);
                printLevel(head->right, level-1);
            }
        }
};

int main(){
    AVL<int> tree;
    // Insert 10 random numbers
    vector<int> v = {23,56,12,34,67,89,45,78,90,1};

    for (int i = 0; i < v.size(); i++)
    {
        tree.insert(v[i]);
    }
    
    // Print the tree
    cout << endl << "Size of the tree: " << tree.size() << endl;
    tree.print();
    // Remove nodes from the tree
    tree.remove(57);
    tree.remove(68);
    tree.remove(79);
    // Print the tree
    cout << endl << "Size of the tree: " << tree.size() << endl;
    tree.print();

    // Print the tree in level order
    cout << endl;
    tree.levelOrder();

    // Search for a node
    int nodeToSearch = 67;
    cout << endl << "Is node " << nodeToSearch << " present in the tree? " << tree.search(nodeToSearch) << endl;

}
