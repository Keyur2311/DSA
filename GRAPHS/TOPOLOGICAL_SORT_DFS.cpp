
#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int src, vector<int> graph[], stack<int> &st, bool *vis)
{
    vis[src] = true;
    for (auto it : graph[src])
    {
        if (vis[it] == false)
        {
            findTopoSort(it,graph,st,vis);
        }
    }
    st.push(src);
}

int main()
{

    // TOPOLOGICAL SORT FOR DIRECTED ACYCLIC GRAPH USING DFS

    // TIME COMPLEXITY  :- O(V+E)
    // SPACE COMPLEXITY :- O(V)
    // AUXILIARY SPACE  :- O(V)

    int V, E;
    cin >> V >> E;

    vector<int> graph[V + 1];

    for (int i = 1; i <= E; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
    }

    bool vis[V + 1] = {0};
    stack<int> st;

    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == false)
        {
            findTopoSort(i, graph, st, vis);
        }
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
