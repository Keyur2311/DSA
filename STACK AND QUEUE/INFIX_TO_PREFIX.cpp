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

string infixToPrefix(string s)
{
    stack<char> optrs;
    stack<string> pre;
    string str = s;

    for (int i = 0; i < int(str.size()); i++)
    {
        char ch = str[i];

        if (ch == '(')
        {
            optrs.push(ch);
        }
        else if (isdigit(ch) || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            string st(1, ch);
            pre.push(st);
        }
        else if (ch == ')')
        {
            while (optrs.top() != '(')
            {
                char opt = optrs.top();
                optrs.pop();

                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();

                string val = "";
                val += opt;
                val += v1;
                val += v2;
                pre.push(val);
            }
            optrs.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!optrs.empty() && optrs.top() != '(' && (precedence(ch) <= precedence(optrs.top())))
            {
                char opt = optrs.top();
                optrs.pop();

                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();

                string val = "";
                val += opt;
                val += v1;
                val += v2;
                pre.push(val);
            }
            optrs.push(ch);
        }
    }

    while (!optrs.empty())
    {
        char opt = optrs.top();
        optrs.pop();

        string v2 = pre.top();
        pre.pop();
        string v1 = pre.top();
        pre.pop();

        string val = "";
        val += opt;
        val += v1;
        val += v2;
        pre.push(val);
    }

    return pre.top();
}
int main()
{

    // <---- INFIX TO PREFIX ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (infixToPrefix(str)) << endl;
}

