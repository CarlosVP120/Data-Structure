#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Node
{
    int value;
    int priority;
};

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
    void push(int);
    Node *pop();
    int top();
    bool empty();
    int size();

    void displayIndex(int);
    void display();
};

void priority_queue::push(int value)
{
    if (NumNodes == N - 1)
    {
        cout << "Priority Queue is full" << endl;
        return; // Salir del ciclo
    }
    // Increase the size
    NumNodes++;

    // Insert the element

    PQ[NumNodes].value = value;
}

Node *priority_queue::pop()
{
    if (NumNodes == -1)
    {
        cout << "Priority Queue is Empty" << endl;
        return NULL;
    }

    int ind = top();

    Node *Aux = &PQ[ind];
    cout << "Element " << Aux->value << " removed" << endl;

    for (int i = ind; i < NumNodes; i++)
    {
        PQ[i] = PQ[i + 1];
    }

    NumNodes--;

    return Aux;
}

int priority_queue::top()
{ // Finds the position of the element with highest priority
    int highestPriority = INT_MIN;
    int ind = -1;

    for (int i = 0; i <= NumNodes; i++)
    {
        if (highestPriority < PQ[i].priority)
        {
            highestPriority = PQ[i].priority;
            ind = i;
        }
        else if (highestPriority == PQ[i].priority && PQ[i].value > PQ[ind].value)
        {
            highestPriority = PQ[i].priority;
            ind = i;
        }

        return ind;
    }
    return ind;
}

void priority_queue::displayIndex(int idx)
{
    cout << PQ[idx].value << endl;
}

void priority_queue::display()
{
    cout << endl
         << "Elements: ";

    for (int i = 0; i <= NumNodes; i++)
    {
        cout << PQ[i].value << " ";
    }
    cout << endl
         << endl;
}

bool priority_queue::empty()
{
    if (NumNodes == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int priority_queue::size()
{
    return NumNodes + 1;
}

int main()
{
    vector<int> values = {45, 25, 33, 45, 51, 64, 75, 81, 93, 18};
    int size = values.size();
    priority_queue P(size);

    for (int i = 0; i < size; i++)
    {
        P.push(values[i]);
    }

    cout << endl
         << "Size: " << P.size();
    P.display();

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
