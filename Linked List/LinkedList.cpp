//cpp base
#include <iostream>

using namespace std;

struct LinkedList{
    int data;
    LinkedList *next;
} node;

int main()
{
    LinkedList *head;

    LinkedList *newNode = new LinkedList();
    newNode->data = 8;
    newNode->next = NULL;

    head = newNode;

    LinkedList *newNode1 = new LinkedList();
    newNode1 -> data = 10;
    newNode1 -> next = NULL;

    head -> next = newNode1;

    LinkedList *tmp = head;

    while (tmp != NULL){
        cout << tmp -> data << endl;
        tmp = tmp -> next;
    }

    return 0;
}