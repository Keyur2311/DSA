#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

int sizeOfLinkedList(Node *&head)
{
    if (head == NULL)
        return 0;

    Node *temp = head;

    int ctr = 0;
    while (temp != NULL)
    {
        ctr++;
        temp = temp->next;
    }

    return ctr;
}
void display(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "";
        if (temp->next != NULL)
        {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}
Node *getNodeAt(Node *&head, int idx)
{
    Node *temp = head;
    for (int i = 0; i < idx; i++)
    {
        temp = temp->next;
    }
    return temp;
}

void reverseDataIterative(Node *&head)
{
    int li = 0;
    int ri = sizeOfLinkedList(head) - 1;

    while (li < ri)
    {
        Node *l = getNodeAt(head, li);
        Node *r = getNodeAt(head, ri);

        swap(l->data, r->data);
        li++;
        ri--;
    }
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);

    insertAtHead(head, 11);

    // <----- REVERSE SINGLY LINKEDLIST (DATA RECURSIVE)----->
    // CHANGE DATA PROPERTY OF LINKEDLIST (NOT NEXT)

    display(head);
    reverseDataIterative(head);
    display(head);
}
