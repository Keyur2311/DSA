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

int kthFromLast(Node *&head, int k)
{

    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
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

    // <----- KTH ELEMENT FROM LAST IN LINKEDLIST   ----->

    /* CONSTRAINTS :- A. ONLY USING ITERATIVELY
                      B. YOU CAN'T USE SIZE PROPERTY
                      C. ONLY SINGLE ITERATION IS ALLOWED
    */
    // TIME COMPLEXITY :- O(N)

    int k;
    cin >> k;
    int kth = kthFromLast(head, k);
    cout << kth << endl;
}

