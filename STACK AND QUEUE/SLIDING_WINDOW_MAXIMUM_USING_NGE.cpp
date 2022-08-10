#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> arr)
{
    int n = (int)arr.size();

    vector<int> ans(n);
    ans[n - 1] = n;
    stack<int> st;
    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans[i] = n;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(i);
    }

    return ans;
}
int main()
{

    //  SLIDING WINDOW MAXIMUM USING NGE TO THE RIGHT
    // TIME COMPLEXITY  :- O(N)  (MAY BE O(N*K) IN RARE CASE)
    // SPACE COMPLEXITY :- O(N)

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> v = NGE(arr);

    for (int i = 0; i < n - k + 1; i++)
    {
        int j = i;
        while (v[j] < i + k)
        {
            j = v[j];
        }

        cout << arr[j] << " ";
    }
    cout << endl;
}
