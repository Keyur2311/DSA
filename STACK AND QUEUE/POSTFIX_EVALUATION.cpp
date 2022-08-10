
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

int postfixEvaluation(string s)
{
    stack<int> val;

    for (int i = 0; i < (s.size()); i++)
    {
        char ch = s[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int v2 = val.top();
            val.pop();
            int v1 = val.top();
            val.pop();

            val.push(operation(v1, v2, ch));
        }
        else
        {
            val.push(ch - '0');
        }
    }

    return val.top();
}

int main()
{

    // <---- POSTFIX EVALUATION ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (postfixEvaluation(str)) << endl;
}
