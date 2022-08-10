#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> arr)
{
    int n = (int)arr.size();

    vector<int> ans(n);
    ans[0] = -1;
    stack<int> st;
    st.push(0);

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = arr[st.top()];
        }

        st.push(i);
    }

    return ans;
}
int main()
{

    //  NEXT GREATER ELEMENT TO THE LEFT USING STACK
    // TIME COMPLEXITY  :- O(N)
    // SPACE COMPLEXITY :- O(N)

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = NGE(arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
