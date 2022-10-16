#include <iostream>

using namespace std;

struct Node {
    int data;
};

class Deque {
    private:
        Node *D;
        int N,front,rear;
    public:
        Deque(int size) {
            N = size;
            D = new Node[size];
            front = -1;
            rear = -1;
        }
        ~Deque() {
            delete[] D;
        }
        void Push_back(int);
        void Push_front(int);
        Node *Pop_front();
        Node *Pop_back();
        void Display();

};

void Deque::Push_back(int value){
    if ((front == 0 && rear==N-1) || front == rear+1 )
    {
        cout << "The Deque is full" << endl;
        return;
    }
    
    if (front==-1)
    {
        front = 0;
    }

    rear++;

    D[rear].data = value;
    
}

void Deque::Push_front(int value){
    if ((front == 0 && rear==N-1) || front == rear+1 )
    {
        cout << "The Deque is full" << endl;
        return;
    }
    
    if (front<1)
    {
        front = N-1;
    } else {
        front--;
    }

    D[front].data = value;
    
}

Node *Deque::Pop_back(){
    if (front == -1)
    {
        cout << "The Deque is empty" << endl;
        return NULL;
    }
    
    Node *Aux = &D[rear];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    } else {
        if (rear == 0)
        {
            rear = N-1;
        } else {
            rear--;
        }
    }
    
    return Aux;
}

Node *Deque::Pop_front(){
    if (front == -1)
    {
        cout << "The Deque is empty" << endl;
        return NULL;
    }
    
    Node *Aux = &D[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    } else {
        if (front == N-1)
        {
            front = 0;
        } else {
            front++;
        }
    }
    
    return Aux;
}

void Deque::Display(){
    if (front == -1)
    {
        cout << "The Deque is empty" << endl;
        return;
    }
    
    cout << "Elements: ";

    int end = (front > rear)? (N-1) : rear;
    for (int i = front; i <= end; i++)
    {
        cout << D[i].data << " ";
    }

    int init = (front > rear)? 0 : front;
    for (int i = init; i <= rear; i++)
    {
        cout << D[i].data << " ";
    }
    cout << endl;
}

int main()
{
    Deque D(4);
    D.Push_back(8);
    D.Push_back(5);
    D.Push_front(7);
    D.Push_front(10);
    D.Display();

    D.Push_back(11);

    D.Pop_back();
    D.Pop_front();
    D.Display();

    D.Push_front(55);
    D.Push_back(47);
    D.Display();

    return 0;
}