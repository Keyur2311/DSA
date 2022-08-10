#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            char ch1 = s[i];
            char ch2;
            if (s[i] == ')')
                ch2 = '(';
            if (s[i] == '}')
                ch2 = '{';
            if (s[i] == ']')
                ch2 = '[';

            if (st.empty())
                return false;
            if (ch2 != st.top())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }

    if (st.empty())
        return true;
    return false;
}
int main()
{

    // <---- BALANCED BRACKTES ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    cin >> str;

    if (isBalanced(str))
    {
        cout << "BALANCED BRACKETS" << endl;
    }
    else
    {
        cout << "NOT BALANCED" << endl;
    }
}

