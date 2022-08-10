#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node() {}
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
}
void insertAtTail(Node *&head, int val)
{

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    Node *n = new Node(val);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}
void display(Node *&head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtKth(Node *&head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            insertAtHead(head, val);
            return;
        }
        else
        {
            return;
        }
    }

    if (k == 1)
    {
        insertAtHead(head, val);
        return;
    }

    Node *temp = head;

    Node *x = new Node(val);

    for (int i = 1; head != NULL && i < k - 1; i++)
    {
        temp = temp->next;
    }

    x->next = temp->next;
    x->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = x;
    }
    temp->next = x;

    return;
}
int main()
{

    // INSERT AT GIVEN POSITION IN DOUBLY LINKEDLIST
    // TIME COMPLEXITY :- O(N)

    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    display(head);

    int val, pos;
    cin >> val >> pos;
    insertAtKth(head, val, pos);

    display(head);
}

