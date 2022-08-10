#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

// <-------- STACK FUNCTIONS ------>
class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }

    int isEmpty()
    {
        return top == NULL;
    }

    void Pop()
    {
        if (isEmpty())
        {
            cout << "STACK IS EMPTY" << endl;
            exit(1);
        }
        Node *todelete = top;
        top = top->next;

        delete todelete;
    }
    void Push(int val)
    {
        Node *temp = new Node();

        if (!temp)
        {
            cout << "STACK OVERFLOW" << endl;
            return;
        }

        temp->data = val;
        temp->next = top;
        top = temp;
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "STACK IS EMPTY" << endl;
            exit(1);
        }
        return top->data;
    }

    void printStack()
    {
        if (top == NULL)
        {
            cout << "STACK IS EMPTY" << endl;
            return;
        }
        Node *temp = top;

        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->next != NULL)
            {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{

    // <----- LINKED LIST IMPLEMENTATION OF STACK  ----->

    /* 
       TIME COMPLEXITY :-  POP  :- O(1)
                           PUSH :- O(1)
                           TOP  :- O(1)
    */
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.printStack();
    s.Pop();
    cout << s.Top() << endl;
    s.Pop();
    s.Pop();
    if (s.isEmpty())
    {
        cout << "STACK IS EMPTY" << endl;
    }
}
