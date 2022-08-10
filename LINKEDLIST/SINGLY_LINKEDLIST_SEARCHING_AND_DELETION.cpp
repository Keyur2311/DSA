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

//Seach any element in LinkedList
bool searchinLinkedList(Node *&head, int key)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(Node *&head)
{
    Node *todelete = head;
    head = head->next;

    delete todelete;
}
void deleteInLinkedList(Node *&head, int key)
{
    if (head == NULL)
        return;

    if (head->data == key) // deleteAtHead
    {
        deleteAtHead(head);
        return;
    }

    Node *temp = head;

    while (temp->next->data != key)
    {
        temp = temp->next;
    }

    Node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
    return;
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
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);

    insertAtHead(head, 11);

    // <----- SINGLY LINKEDLIST SEARCHING AND DELETION ----->

    // TIME COMPLEXITY OF SEARCHING  :- O(N)
    // TIME COMPLEXITY OF DELETION   :- O(N)

    display(head);

    // SEARCH ELEMENT 30
    if (searchinLinkedList(head, 10))
    {
        cout << "ELEMENT FOUND" << endl;
    }
    else
    {
        cout << "ELEMENT NOT FOUND" << endl;
    }

    // DELETION

    // IF ELEMENT IS PRESENT IN LINKEDLIST THEN DELETE IT
    if (searchinLinkedList(head, 11))
    {
        deleteInLinkedList(head, 11);
    }

    display(head);
}

