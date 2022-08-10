#include <bits/stdc++.h>
using namespace std;


string postfixToInfix(string s)
{
    stack<string> infix;

    for (int i = 0; i < (s.size()); i++)
    {
        char ch = s[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            string infv2 = infix.top();
            infix.pop();
            string infv1 = infix.top();
            infix.pop();

            string v(1, ch);
            string s = "(" + infv1 + v + infv2 + ")";

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

    // <---- POSTFIX TO INFIX  CONVERSION ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (postfixToInfix(str)) << endl;
}

