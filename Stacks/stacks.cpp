#include <iostream>

using namespace std;

struct Node
{
    int num;
};

class Stack {
    private:
        int N, Top;
        Node *st;
    public:
        Stack(int size){
            Top = -1;
            N = size;

            st = new struct Node[N];
        }
        ~Stack() {
            cout << "Destructor: Erase Stack" << endl;
            delete[] st;
        }
        void Push(int);
        struct Node *Pop();
        int *Peek();
        bool isEmpty();
};  

void Stack::Push(int NUM) {
    if (Top == N-1)
    {
        cout << "The stack is full (OverFlow)." << endl;
    } else {
        Top ++;
        st[Top].num = NUM;
    }
    
};

struct Node *Stack::Pop(void) {
    if (Top < 0)
    {
        cout << "The stack is empty (UnderFlow)" << endl;
        return NULL;
    }

    Top--;
    return &st[Top+1];
    
};

bool Stack::isEmpty(){
    if (Top < 0)
    {
        return true;
    }
    return false;
    
}

int *Stack::Peek(void){
    if (Top < 0)
    {
        return NULL;
    }
    return &(st[Top].num);
}

int main(void){

    int size;
    cout << "Insert size of the stack: ";
    cin >> size;

    Stack P(size);

    int x;
    for (int i = 0; i < size; i++)
    {
       cout << "Enter Value: ";
       cin >> x;
       P.Push(x);
    }
    P.Push(100);
    
    int *v;
    v = P.Peek();
    cout << "The value at top is: " << *v << endl;

    while (!P.isEmpty())
    {
        cout << P.Pop()->num << " " << endl;
    }

    return (0);
}