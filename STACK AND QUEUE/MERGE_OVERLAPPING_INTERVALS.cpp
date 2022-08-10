#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return false;
    else
    {
        return true;
    }
}
int main()
{

    int n;
    cin >> n;

    vector<pair<int, int>> vp;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        vp.push_back(make_pair(x, y));
    }

    sort(vp.begin(), vp.end(), cmp);
    stack<pair<int, int>> st;

    st.push(make_pair(vp[0].first, vp[0].second));
    for (int i = 1; i < n; i++)
    {
        auto z = st.top();
        int x = z.first;
        int y = z.second;

        if (vp[i].first <= y)
        {
            if (vp[i].second > y)
            {
                st.pop();
                st.push(make_pair(x, vp[i].second));
            }
        }
        else
        {
            st.push(make_pair(vp[i].first, vp[i].second));
        }
    }

    stack<pair<int, int>> ans;
    while (!st.empty())
    {
        auto it = st.top();
        ans.push(it);
        st.pop();
    }

    while (!ans.empty())
    {
        auto it = ans.top();
        cout << it.first << " " << it.second << endl;
        ans.pop();
    }
}

