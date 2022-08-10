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

int findIntersection(Node *head1, Node *head2)
{
    int s1 = sizeOfLinkedList(head1);
    int s2 = sizeOfLinkedList(head2);

    Node *temp1;
    Node *temp2;
    int x;

    // temp1 is pointing to bigger linkedlist
    if (s1 > s2)
    {
        x = s1 - s2;
        temp1 = head1;
        temp2 = head2;
    }
    else
    {
        x = s2 - s1;
        temp1 = head2;
        temp2 = head1;
    }

    while (x--)
    {
        if (temp1 == NULL)
            return -1;
        temp1 = temp1->next;
    }

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
            return temp1->data;
        temp1 = temp2->next;
        temp2 = temp2->next;
    }
    return temp2->data;
}

int main()
{

    // INTERSECTION OF TWO LINKEDLIST (METHOD 1)

    // TIME COMPLEXITY :- O(N+M)
    // AUXILIARY SPACE :- O(1)

    Node *newNode;
    Node *head1 = new Node();
    head1->data = 10;

    Node *head2 = new Node();
    head2->data = 3;

    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;

    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;

    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    // display(head1);
    // display(head2);

    cout <<"INTERSECTION POINT:- "<< findIntersection(head1, head2) << endl;
}


