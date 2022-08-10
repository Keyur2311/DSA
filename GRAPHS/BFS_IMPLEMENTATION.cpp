#include <bits/stdc++.h>
using namespace std;

void BFS(int src, vector<int> graph[], bool *vis)
{

    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";
        for (auto it : graph[curr])
        {
            if (vis[it] == false)
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
}
int main()
{

    // BFS FOR UNWEIGHTED UNDIRECTED GRAPH
    // -> ONLY FOR ONE CONNECTED COMPONENT

    // TIME COMPLEXITY  :- O(V+E)
    // SPACE COMPLEXITY :- O(V+E)

    int V, E;
    cin >> V >> E;

    vector<int> graph[V + 1];

    for (int i = 1; i <= E; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool vis[V + 1] = {0};

    BFS(1, graph, vis);
}
