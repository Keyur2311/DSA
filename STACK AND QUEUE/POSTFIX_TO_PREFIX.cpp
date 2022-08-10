#include <bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s)
{
    stack<string> pre;

    for (int i = 0; i < (s.size()); i++)
    {
        char ch = s[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            string prev2 = pre.top();
            pre.pop();
            string prev1 = pre.top();
            pre.pop();

            string v(1, ch);
            string s = ch + prev1 + prev2;
            pre.push(s);
        }
        else
        {
            string s(1, ch);
            pre.push(s);
        }
    }

    return pre.top();
}
int main()
{

    // <---- POSTFIX TO PREFIX  CONVERSION ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (postfixToPrefix(str)) << endl;
}

