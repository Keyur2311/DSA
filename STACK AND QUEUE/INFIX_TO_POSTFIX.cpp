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

string infixToPostfix(string s)
{
    stack<char> optrs;
    stack<string> post;
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
            post.push(st);
        }
        else if (ch == ')')
        {
            while (optrs.top() != '(')
            {
                char opt = optrs.top();
                optrs.pop();

                string v2 = post.top();
                post.pop();
                string v1 = post.top();
                post.pop();

                string val = "";
                val += v1;
                val += v2;
                val += opt;
                post.push(val);
            }
            optrs.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!optrs.empty() && optrs.top() != '(' && (precedence(ch) <= precedence(optrs.top())))
            {
                char opt = optrs.top();
                optrs.pop();

                string v2 = post.top();
                post.pop();
                string v1 = post.top();
                post.pop();

                string val = "";
                val += v1;
                val += v2;
                val += opt;
                post.push(val);
            }
            optrs.push(ch);
        }
    }

    while (!optrs.empty())
    {
        char opt = optrs.top();
        optrs.pop();

        string v2 = post.top();
        post.pop();
        string v1 = post.top();
        post.pop();

        string val = "";
        val += v1;
        val += v2;
        val += opt;
        post.push(val);
    }

    return post.top();
}
int main()
{

    // <---- INFIX TO POSTFIX ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (infixToPostfix(str)) << endl;
}

