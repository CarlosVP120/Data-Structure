#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
    Node *prev;
};

//Insert at the beginning
Node* create_begin(Node *head, int val){ // O(1)
    Node *new_node = new Node();
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (head)
    {      
        new_node->next = head;
        head->prev = new_node;
    }
    return new_node;

}

//Insert at the end
Node* create_end(Node *head, int val){ //O(n)
    Node *new_node = new Node();
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (head)
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    else
    {
        head = new_node;
    }
    return head;
}

//Insert at specific position
Node* create_after(Node *head, int val, int after){ //O(n)
    Node *new_node = new Node();
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (head)
    {
        Node *temp = head;
        while (temp->val != after)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        if (new_node->next)
        {
            new_node->next->prev = new_node;
        }
    }
    return head;
}

//Return the index of the value
int read(Node *head, int val){ //O(n)
    int index = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->val == val)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

//Update the value of a node
Node* update(Node *head, int replace_val, int val){ //O(n)
    Node *temp = head;
    while (temp)
    {
        if (temp->val == val)
        {
            temp->val = replace_val;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

//Delete a node
Node* delete_node(Node *head, int val){ //O(n)
    Node *temp = head;
    while (temp)
    {
        if (temp->val == val)
        {
            if (temp->prev)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                head = temp->next;
            }
            if (temp->next)
            {
                temp->next->prev = temp->prev;
            }
            delete temp;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//Print the list
void print_list(Node *head){ //O(n)
    cout << "NULL <-";
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " <-> ";
        curr = curr->next;
    }

    cout << "NULL" << endl;
    
}

int main() {

    Node *head = NULL;

    head = create_begin(head,30);
    head = create_begin(head,20);
    head = create_begin(head,10);

    head = create_after(head, 40, 30);
    head = create_after(head, 50, 40);
    head = create_after(head, 60, 50);

    head = create_end(head,70);
    head = create_end(head,80);
    head = create_end(head,90);

    head = delete_node(head, 90);

    head = update(head, 800, 80);

    cout << endl;
    print_list(head);

    int search_value = 70;
    cout << endl << "Indice del valor " << search_value << ": "<< read(head,search_value) << endl << endl;
}