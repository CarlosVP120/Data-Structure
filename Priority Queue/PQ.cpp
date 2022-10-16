#include <iostream>

using namespace std;

struct Node {
    int value;
    int priority;
};

class PriorQueue {
    private:
        Node *PQ;
        int N, NumNodes;
    public:
        PriorQueue(int size) {
            N = size;
            PQ = new Node[size];
            NumNodes = -1;
        }
        ~PriorQueue() {
            delete[] PQ;
        }
        void Enqueue(int, int);
        Node *Deque();
        int Peek();
        void DisplayIndex(int);
        void Display();
};

void PriorQueue::Enqueue(int value, int priority) {
    if (NumNodes == N-1)
    {
        cout << "Priority Queue is full" << endl;
        return; // Salir del ciclo
    }
    // Increase the size
    NumNodes ++;

    // Insert the element

    PQ[NumNodes].value = value;
    PQ[NumNodes].priority = priority;

}


Node *PriorQueue::Deque() {
    if (NumNodes == -1)
    {
        cout << "Priority Queue is Empty" << endl;
        return NULL;
    }

    int ind = Peek();

    Node *Aux = &PQ[ind];

    for (int i = ind; i < NumNodes; i++)
    {
        PQ[i] = PQ[i+1];

    }

    NumNodes--;

    return Aux;
}

int PriorQueue::Peek() { // Finds the position of the element with highest priority
    int highestPriority = INT_MIN;
    int ind =-1;

    for (int i = 0; i <= NumNodes; i++)
    {
        if (highestPriority < PQ[i].priority)
        {
            highestPriority = PQ[i].priority;
            ind = i;
        } else if (highestPriority == PQ[i].priority && PQ[i].value > PQ[ind].value)
        {
            highestPriority = PQ[i].priority;
            ind = i;
        }
        
        return ind;
    }
    return ind;
}

void PriorQueue::DisplayIndex(int idx) {
    cout << PQ[idx].value << endl << endl;
}

void PriorQueue::Display() {
    cout << "Elements: ";

    for (int i = 0; i <= NumNodes; i++)
    {
        cout << PQ[i].value << " ";
    }
    cout << endl << endl;
}



int main() {
    PriorQueue P(5);

    P.Enqueue(10,2);
    P.Enqueue(14,4);
    P.Enqueue(16,4);
    P.Enqueue(12,3);
    P.Display();

    int indx = P.Peek();
    cout << "Higher priority element: ";
    P.DisplayIndex(indx);

    P.Deque();
    P.Display();

    int index = P.Peek();
    cout << "Higher priority element: ";
    P.DisplayIndex(index);

    P.Deque();
    P.Display();

    int index_second = P.Peek();
    cout << "Higher priority element: ";
    P.DisplayIndex(index_second);

    P.Deque();
    P.Display();

    P.Deque();
    P.Display();

    P.Deque();

    return 0;
}

