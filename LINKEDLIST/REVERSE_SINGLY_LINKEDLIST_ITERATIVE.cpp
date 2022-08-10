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

// <----- REVERSE A LINKEDLIST (ITERATIVE METHOD) ----->

Node *reverseIterative(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nextPtr;

    while (curr != NULL)
    {
        nextPtr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextPtr;
    }
    return prev;
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

    // <----- REVERSE A SINGLY LINKEDLIST (ITERATIVE ) ----->

    // TIME COMPLEXITY  :- O(N)

    Node *head1 = reverseIterative(head);
    display(head1);
}

