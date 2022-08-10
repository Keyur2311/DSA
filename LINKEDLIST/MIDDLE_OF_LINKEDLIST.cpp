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
        temp = temp->next;

    temp->next = newNode;
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

Node *middleInLinkedList(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    // <----- MIDDLE NODE IN LINKEDLIST   ----->

    /* CONSTRAINTS :- A. ONLY USING ITERATIVELY
                      B. YOU CAN'T USE SIZE PROPERTY
                      C. ONLY SINGLE ITERATION IS ALLOWED
    */
    // TIME COMPLEXITY :- O(N)

    Node *middle = middleInLinkedList(head);
    cout << middle->data << endl;
}

