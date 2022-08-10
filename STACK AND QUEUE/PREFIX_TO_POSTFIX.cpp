#include <bits/stdc++.h>
using namespace std;

string prefixToPostfix(string s)
{
    stack<string> post;

    for (int i = (int)(s.size() - 1); i >= 0; i--)
    {
        char ch = s[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            string prev1 = post.top();
            post.pop();
            string prev2 = post.top();
            post.pop();

            string v(1, ch);
            string s = prev1 + prev2 + ch;
            post.push(s);
        }
        else
        {
            string s(1, ch);
            post.push(s);
        }
    }

    return post.top();
}
int main()
{

    // <---- PREFIX TO POSTFIX  CONVERSION ---->

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    getline(cin, str);

    cout << (prefixToPostfix(str)) << endl;
}

