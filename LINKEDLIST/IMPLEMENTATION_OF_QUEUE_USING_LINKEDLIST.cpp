#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        next = NULL;
        data = val;
    }
};

// <--------    QUEUE FUNCTIONS ------>
class Queue
{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return rear == NULL;
    }

    void enQueue(int val)
    {
        Node *temp = new Node(val);
        if (isEmpty())
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
        return;
    }
    void deQueue()
    {
        if (isEmpty())
        {
            return;
        }

        Node *todelete = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete todelete;
    }
};
int main()
{

    // <----- LINKED LIST IMPLEMENTATION OF QUEUE  ----->

    /*
       TIME COMPLEXITY :-  ENQUEUE :- O(1)
                           DEQUEUE :- O(1)
                           FRONT   :- O(1)
                           REAR    :- O(1)
    */

    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    if (q.isEmpty())
    {
        cout << "QUEUE IS EMPTY" << endl;
    }

    q.enQueue(11);
    q.enQueue(12);
    q.enQueue(13);

    cout << (q.front)->data << endl;
    cout << (q.rear)->data << endl;
}
