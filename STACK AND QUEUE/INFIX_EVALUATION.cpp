#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 2;
    }
}

int operation(int v1, int v2, char optr)
{
    if (optr == '+')
    {
        return v1 + v2;
    }
    else if (optr == '-')
    {
        return v1 - v2;
    }
    else if (optr == '*')
    {
        return v1 * v2;
    }
    else
    {
        return v1 / v2;
    }
}

int infixEvaluation(string s)
{
    stack<int> oprnds;
    stack<char> optrs;
    string str = s;

    for (int i = 0; i < int(str.size()); i++)
    {
        char ch = str[i];

        if (ch == '(')
        {
            optrs.push(ch);
        }
        else if (isdigit(ch))
        {
            oprnds.push(ch - '0');
        }
        else if (ch == ')')
        {

            while (optrs.top() != '(')
            {
                char opt = optrs.top();
                optrs.pop();

                int v2 = oprnds.top();
                oprnds.pop();
                int v1 = oprnds.top();
                oprnds.pop();

                int val = operation(v1, v2, opt);
                oprnds.push(val);
            }
            optrs.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {

            while (!optrs.empty() && optrs.top() != '(' && (precedence(ch) <= precedence(optrs.top())))
            {
                char opt = optrs.top();
                optrs.pop();

                int v2 = oprnds.top();
                oprnds.pop();
                int v1 = oprnds.top();
                oprnds.pop();

                int val = operation(v1, v2, opt);
                oprnds.push(val);
            }
            optrs.push(ch);
        }
    }

    while (!optrs.empty())
    {
        char opt = optrs.top();
        optrs.pop();

        int v2 = oprnds.top();
        oprnds.pop();
        int v1 = oprnds.top();
        oprnds.pop();

        int val = operation(v1, v2, opt);
        oprnds.push(val);
    }
    return (int)oprnds.top();
}
int main()
{

    // <---- INFIX EVALUATION ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (infixEvaluation(str)) << endl;
}

