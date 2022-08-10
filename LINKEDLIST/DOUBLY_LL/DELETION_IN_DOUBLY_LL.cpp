
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

void deleteAtHead(Node *&head)
{
    if (head == NULL)
        return;

    Node *todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
    return;
}

void deleteAtKth(Node *&head, int pos)
{
    if (head == NULL)
        return;

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
        return;

    Node *todelete = temp->next;

    if (temp->next->next != NULL)
    {
        temp->next->next->prev = temp;
    }
    temp->next = temp->next->next;

    delete todelete;
    return;
}

void deletGivenValue(Node *&head, int val)
{
    if (head == NULL)
        return;

    if (head->data == val)
    {
        head = head->next;
        head->prev = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->data == val)
            break;
        temp = temp->next;
    }

    if (temp->next == NULL)
        return;

    Node *todelete = temp->next;

    if (temp->next->next != NULL)
    {
        temp->next->next->prev = temp;
    }
    temp->next = temp->next->next;

    delete todelete;
    return;
}
int main()
{

    // DELETION IN DOUBLY LINKEDLIST
    /* TIME COMPLEXITY :-  DELETE AT HEAD :- O(1)
                           ELSE O(N)
    */

    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    display(head);

    deleteAtKth(head, 4);     // DELETE AT GIVEN POSITION
    deleteAtHead(head);       // DELETE AT HEAD
    deletGivenValue(head, 3); // DELETE GIVEN NUMBER

    display(head);
}
