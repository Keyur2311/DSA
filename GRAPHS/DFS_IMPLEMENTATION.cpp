#include <bits/stdc++.h>
using namespace std;

void DFS(int src, vector<int> graph[], bool *vis)
{
    vis[src] = true;

    cout << src << " ";
    for (auto it : graph[src])
    {
        if (vis[it] == false)
            DFS(it, graph, vis);
    }
}
int main()
{

    // DFS FOR UNWEIGHTED UNDIRECTED GRAPH

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

    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == false)
            DFS(i, graph, vis);
    }
}
