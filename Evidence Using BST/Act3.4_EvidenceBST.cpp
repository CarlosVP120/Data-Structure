#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

// Authors:
// Carlos Alberto Veryan Peña A01641147
// Diego Partida Romero A01641113

// Date:
// 24/10/2022

struct Node
{
    long long data;
    Node *left, *right;
    int count = 1;

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

    void Insert(long long &, Node *&);                               // O(log n)
    void InOrder(Node *, ofstream &);                                // O(n)
    void DeleteNode(int &, Node *&);                                 // O(log n)
    void CountRepeated(Node *&, vector<long long> &, vector<int> &); // O(n)

public:
    BST() : Root(NULL){};

    ~BST()
    {
        cout << "Deleting the tree..." << endl;
        DeleteBST(Root);
        cout << "\nDestructor: BST deleted\n";
    }

    void Insert(long long &value) { Insert(value, Root); }                                                      // Insert a node in the BST O(log n)
    void InOrder(ofstream &out) { InOrder(Root, out); }                                                         // InOrder traversal O(n)
    void DeleteNode(int &value) { DeleteNode(value, Root); }                                                    // Delete a node from BST // O(log n)
    void DeleteBST(Node *&);                                                                                    // Delete the BST // O(n)
    void CountRepeated(vector<long long> &values, vector<int> &counts) { CountRepeated(Root, values, counts); } // O(n)
};

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
            root->count++;
        }
    }
}

string intToIP(long long ip)
{ // O(n)
    string iPstr = to_string(ip);
    string finalIP = "";
    int count = 0;
    for (int i = 0; i < iPstr.length()+1; i++)
    { // O(n)
        if (count == 1 || count == 3 || count == 6)
        {
            finalIP += iPstr[i];
            finalIP += ".";
            count ++;
        } 
        else
        {
            finalIP += iPstr[i];
            count++;
        }
    }
    finalIP.pop_back();
    return finalIP;
}

void BST::CountRepeated(Node *&root, vector<long long> &iplist, vector<int> &countlist)
{ // O(n)
    if (root != NULL)
    {
        CountRepeated(root->left, iplist, countlist);
        if (root->count > 1)
        {
            iplist.push_back(root->data);
            countlist.push_back(root->count);
        }
        CountRepeated(root->right, iplist, countlist);
    }
}

void BST::InOrder(Node *root, ofstream &file)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left, file);
    // file << root->count <<endl;
    file << root->data << endl;
    InOrder(root->right, file);
}

void BST::DeleteBST(Node *&root)
{
    if (root != NULL)
    {
        // cout << "Deleting " << root->data << endl;
        DeleteBST(root->left);
        DeleteBST(root->right);
        delete root;
        root = NULL;
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
    for (int i = 2; i < iPs.size(); i++)
    {
        while (iPs[i].length() < 3)
        {
            iPs[i] = "0" + iPs[i];
        }
    }
    
    return iPs[0] + "." + iPs[1] + "." + iPs[2] + "." + iPs[3];
}

vector<string> merge(vector<string> left, vector<string> right)
{ // O(n)
    vector<string> result;
    while (left.size() > 0 || right.size() > 0)
    {
        if (left.size() > 0 && right.size() > 0)
        {
            if (ipToInt(getIP(left.front())) <= ipToInt(getIP(right.front())))
            {
                result.push_back(left.front());
                left.erase(left.begin());
            }
            else
            {
                result.push_back(right.front());
                right.erase(right.begin());
            }
        }
        else if (left.size() > 0)
        {
            for (int i = 0; i < left.size(); i++)
            {
                result.push_back(left[i]);
            }
            break;
        }
        else if (right.size() > 0)
        {
            for (int i = 0; i < right.size(); i++)
            {
                result.push_back(right[i]);
            }
            break;
        }
    }
    return result;
}

vector<string> mergeSort(vector<string> array)
{ // O(n)
    if (array.size() == 1)
    {
        return array;
    }
    vector<string> left;
    vector<string> right;
    for (int i = 0; i < array.size() / 2; i++)
    {
        left.push_back(array[i]);
    }
    for (int i = array.size() / 2; i < array.size(); i++)
    {
        right.push_back(array[i]);
    }
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

// MAIN
int main()
{
    cout << "Act 3.4 - Comprehensive BST activity (competence evidence)" << endl;

    cout << "Authors: \nCarlos Alberto Veryan Peña A01641147 \nDiego Partida Romero A01641113" << endl;
    cout << "\nDate: 24/10/2022" << endl;

    BST Tree;

    ifstream file("Bitacora.txt");
    string line;
    vector<string> lines;
    while (getline(file, line))
    {
        if (line[4] >= '0' && line[4] <= '9' && line[5] == ' ')
        {
            line.insert(4, "0");
        }
        if (line[7] >= '0' && line[7] <= '9' && line[8] == ':')
        {
            line.insert(7, "0");
        }
        lines.push_back(line);
    }
    file.close();

    vector<string> sortedLines;

    // Sort the lines with merge sort
    sortedLines = mergeSort(lines);

    // Save the sorted lines in a new file
    ofstream newFile1("Sorted.txt");
    for (int i = 0; i < sortedLines.size(); i++)
    {
        newFile1 << sortedLines[i] << endl;
    }
    newFile1.close();

    for (int i = 0; i < sortedLines.size(); i++)
    {
        string ip = getIP(sortedLines[i]);
        long long ipInt = ipToInt(ip);
        Tree.Insert(ipInt);
    }

    vector<long long> iplist;
    vector<int> countlist;
    Tree.CountRepeated(iplist, countlist);

    for (int i = 0; i < countlist.size(); i++)
    {
        for (int j = i + 1; j < countlist.size(); j++)
        {
            if (countlist[i] < countlist[j])
            {
                int temp = countlist[i];
                countlist[i] = countlist[j];
                countlist[j] = temp;

                long long temp2 = iplist[i];
                iplist[i] = iplist[j];
                iplist[j] = temp2;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {

        cout << intToIP(iplist[i]) << " is repeated: " << countlist[i] << " times" << endl;
    }

    return 0;
}
