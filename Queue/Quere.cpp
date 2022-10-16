#include <iostream>

using namespace std;

struct Node
{
    int value;
};

class Queue {
    private:
        int front,rear, N;
        Node *Q;
    public:
        Queue(int size){
            N = size;
            Q = new Node[size];
            front = -1;
            rear = -1;
        }
        ~Queue() {
            cout << "Destructor: Erase Queue" << endl;
            delete[] Q;
        }
        void Enqueue(int);
        Node *Dequeue();
        void Display();
        bool IsEmpty();
};  

void Queue::Enqueue(int n) {
    if (front == 0 && rear == N-1)
    {
        cout << "The Queue is full." << endl;
    } else {
        if (front == -1)
        {
            front = 0;
        }
        rear ++;

        Q[rear].value = n;
        
    }
    
};

struct Node *Queue::Dequeue(void) {
    if (front == -1)
    {
        cout << "The Queue is empty." << endl;
        return NULL;
    }

    Node *Aux = &Q[front];

    if (front >= rear)
    {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    
    return Aux;
};


bool Queue::IsEmpty(){
    if (front == -1)
    {
        return true;
    }
    return false;
    
}

void Queue::Display(){
    if (IsEmpty())
    {
        cout << "Empty Queue" << endl;
    } else {
        cout << endl << "Front -> ";

        for (int i = front; i <= rear; i++)
        {
            cout << Q[i].value << " ";
        }

        cout << "<- Rear" << endl << endl;
        
    }
}

int main(void){

    Queue C(3);

    int x;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter value: ";
        cin >> x;
        C.Enqueue(x);
    }
    
    C.Display();

    while (!C.IsEmpty())
    {
        cout << C.Dequeue()->value << " " << endl;
    }

    return (0);
}