#include <iostream>
#include <climits>

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
    void push(int, int);
    Node *pop();
    int top();
    bool empty();
    int size();

    void displayIndex(int);
    void display();
};

void priority_queue::push(int value, int priority)
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
    PQ[NumNodes].priority = priority;
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
    cout << PQ[idx].value << endl
         << endl;
}

void priority_queue::display()
{
    cout << "Elements: ";

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
    priority_queue P(5);

    P.push(10, 2);
    P.push(14, 4);
    P.push(16, 4);
    P.push(12, 3);
    P.display();

    int indx = P.top();
    cout << "Higher priority element: ";
    P.displayIndex(indx);

    P.pop();
    P.display();

    int index = P.top();
    cout << "Higher priority element: ";
    P.displayIndex(index);

    P.pop();
    P.display();

    int index_second = P.top();
    cout << "Higher priority element: ";
    P.displayIndex(index_second);

    P.pop();
    P.display();

    P.pop();
    P.display();

    P.pop();

    return 0;
}
