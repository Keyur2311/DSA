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

Node *Intersection(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            break;
    }
    if (fast != slow)
        return NULL; // CYCLE NOT PRESENT

    Node *temp = head;
    while (temp != fast)
    {
        temp = temp->next;
        fast = fast->next;
    }

    return temp;
}
Node *findIntersection(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    Node *tail = head1;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = head2;


    Node *ans = Intersection(head1);

    tail->next = NULL; // BREAK THE CYCLE BEFORE RETURNING ANS

    return ans;
}

int main()
{

    // INTERSECTION OF TWO LINKEDLIST (METHOD 2) (CYCLE METHOD)

    // STEP 1:- MAKE A CYCLE (JOINT THE TAIL(LAST NODE) OF LINKEDLIST TO HEAD1 OR HEAD2)
    // STEP 2:- THEN QUE IS BECAME LIKE FIND CYCLE NODE ( NODE AT WHICH CYCLE STARTS)
    // STEP 3:-  REMOVE OR BREAK THE CYCLE AND RETURN THE ANS NODE

    // TIME COMPLEXITY :- O(N)
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

    Node *ans = findIntersection(head1, head2);
    cout << ans->data << endl;
}

