#include <bits/stdc++.h>
using namespace std;

bool isDuplicate(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == ')')
        {
            int Count = 0;
            char top = s.top();
            s.pop();
            while (top != '(')
            {
                top = s.top();
                s.pop();
                Count++;
            }
            if (Count == 0)
            {
                return true;
            }
        }
        else
        {
            s.push(ch);
        }
    }
    return false;
}
int main()
{

    // <---- DUPLICATE BRACKTES ---->

    // EX :- ((a+b)+(c+d)) --> No duplicates
    //    :- ((a+b))     --> Duplicate present (outer brackets are useless)

    // TIME COMPLEXITY :- O(N)
    // SPACE COMPLEXITY :- O(N)

    string str;
    cin >> str;

    if (isDuplicate(str))
    {
        cout << "Duplicate" << endl;
    }
    else
    {
        cout << "Not Duplicate" << endl;
    }
}
