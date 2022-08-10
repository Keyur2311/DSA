#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node() {}

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
void makeloop(Node *head, int k)
{

    Node *temp = head;
    int count = 1;
    while (count < k)
    {
        temp = temp->next;
        count++;
    }

    Node *joint_point = temp;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = joint_point;
}


Node *cycleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    bool cycle = false;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cycle = true;
            break;
        }
    }

    if (!cycle)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp != fast)
    {
        temp = temp->next;
        fast = fast->next;
    }

    return temp;
}

int main()
{

    // CYCLE NODE IN LINKEDLIST
    // CYCLE NODE:- NODE AT WHICH THE CYCLE IS STARTED

    // TIME COMPLEXITY :- O(N)
    // AUXILIARY SPACE :-

    Node *head = new Node(10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);

    makeloop(head, 5);
    Node *cycleNODE = cycleNode(head);
    if (cycleNODE != NULL)
        cout << cycleNODE->data << endl;
}

