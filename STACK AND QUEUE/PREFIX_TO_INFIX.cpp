#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string s)
{
    stack<string> infix;

    for (int i = (int)(s.size() - 1); i >= 0; i--)
    {
        char ch = s[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            string prev1 = infix.top();
            infix.pop();
            string prev2 = infix.top();
            infix.pop();

            string v(1, ch);
            string s = "(" + prev1 + ch + prev2 + ")";
            infix.push(s);
        }
        else
        {
            string s(1, ch);
            infix.push(s);
        }
    }

    return infix.top();
}
int main()
{
    // <---- PREFIX TO INFIX CONVERSION ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (prefixToInfix(str)) << endl;
}

