#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// Carlos Alberto Veryan Peña A01641147

// Class for Heap Tree
struct Node
{
    int value;
    int priority;
};

// Class for Priority Queue
class priority_queue
{
private:
    Node *PQ;
    int N, NumNodes;

public:
    priority_queue(int size)
    {
        N = size;
        PQ = new Node[size];
        NumNodes = -1;
    }
    ~priority_queue()
    {
        delete[] PQ;
    }
    void push(int); // Insert a node in the priority queue O(logN)
    Node *pop();    // Delete a node from the priority queue O(logN)
    int top();      // Return the value of the node with highest priority O(1)
    bool empty();   // Check if the priority queue is empty O(1)
    int size();     // Return the size of the priority queue O(1)

    void displayIndex(int); // Display the value and priority of a node at a given index O(1)
    void display();         // Display the value and priority of all nodes in the priority queue O(N)
};

void priority_queue::push(int value) // Insert a node in the priority queue O(logN)
{
    if (NumNodes == N - 1)
    {
        cout << "Priority Queue is full" << endl;
        return; // exit the function
    }
    // Increase the size
    NumNodes++;

    // Insert the element
    PQ[NumNodes].value = value;
}

Node *priority_queue::pop() // Delete a node from the priority queue O(logN)
{
    if (NumNodes == -1) // Check if the priority queue is empty
    {
        cout << "Priority Queue is empty" << endl;
        return NULL; // exit the function
    }

    int ind = top(); // Get the index of the node with highest priority

    Node *Aux = &PQ[ind];                                   // Create a pointer to the node with highest priority
    cout << "Element " << Aux->value << " removed" << endl; // Display the value of the node with highest priority

    for (int i = ind; i < NumNodes; i++) // Shift all the nodes to the left
    {
        PQ[i] = PQ[i + 1];
    }

    NumNodes--; // Decrease the size

    return Aux; // Return the pointer to the node with highest priority
}

int priority_queue::top() // Finds the position of the element with highest priority
{
    int highestPriority = INT_MIN; // Initialize the highest priority with the minimum value of an integer
    int ind = -1;                  // Initialize the index with -1

    for (int i = 0; i <= NumNodes; i++) // Iterate trough all the nodes
    {
        if (highestPriority < PQ[i].priority) // Check if the priority of the current node is higher than the highest priority
        {
            highestPriority = PQ[i].priority; // Update the highest priority
            ind = i;                          // Update the index
        }
        else if (highestPriority == PQ[i].priority && PQ[i].value > PQ[ind].value) // Check if the priority of the current node is equal to the highest priority and the value of the current node is higher than the value of the node with highest priority
        {
            highestPriority = PQ[i].priority; // Update the highest priority
            ind = i;                          // Update the index
        }

        return ind;
    }
    return ind;
}

void priority_queue::displayIndex(int idx) // Display the value and priority of a node at a given index
{
    cout << PQ[idx].value << endl;
}

void priority_queue::display() // Display the value and priority of all nodes in the priority queue
{
    cout << endl
         << "Elements: ";

    for (int i = 0; i <= NumNodes; i++) // Iterate trough all the nodes
    {
        cout << PQ[i].value << " ";
    }

    cout << endl
         << endl;
}

bool priority_queue::empty() // Check if de PQ is empty
{
    if (NumNodes == -1) // Check if the priority queue is empty
    {
        return true;
    }
    else
    {
        return false;
    }
}

int priority_queue::size() // Return the size of the PQ
{
    return NumNodes + 1; // Return the size
}

int main()
{
    // Create a priority queue
    vector<int> values = {45, 25, 33, 45, 51, 64, 75, 81, 93, 18};
    int size = values.size();
    priority_queue P(size);

    // Insert the elements
    for (int i = 0; i < size; i++)
    {
        P.push(values[i]);
    }

    cout << endl
         << "Size: " << P.size();
    P.display();

    // Delete the elements
    while (not P.empty())
    {
        int index = P.top();
        cout << "Higher priority element: ";
        P.displayIndex(index);

        P.pop();
        cout << endl
             << "Size: " << P.size();
        P.display();
    }

    P.pop();
    cout << endl;

    return 0;
}
