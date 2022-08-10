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

bool isCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtHead(head, 11);

    // <----- CYCLE DETECTION IN LINKEDLIST ----->

    // TIME COMPLEXITY :- O(N)

    makeloop(head, 2); // LOOP STARTING ON 2ND POSITION

    if (isCycle(head))
    {
        cout << "CYCLE IS PRESENT" << endl;
    }
    else
    {
        cout << "CYCLE IS NOT PRESENT" << endl;
    }
}

