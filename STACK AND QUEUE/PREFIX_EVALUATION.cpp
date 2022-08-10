#include <bits/stdc++.h>
using namespace std;

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
int prefixEvaluation(string s)
{

    stack<int> val;

    for (int i = (int)(s.size() - 1); i >= 0; i--)
    {
        char ch = s[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int v1 = val.top();
            val.pop();
            int v2 = val.top();
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
    // <---- PREFIX EVALUATION ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (prefixEvaluation(str)) << endl;
}

