#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector<int> graph[], bool *vis)
{
    vis[node] = true;

    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            return checkForCycle(it, node, graph, vis);
        }
        else if (parent != it)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> graph[])
{
    bool vis[V + 1] = {0};

    for (int i = 1; i <= V; i++)
    {

        if (vis[i] == false)
        {
            if (checkForCycle(i, -1, graph, vis))
                return true;
        }
    }

    return false;
}
int main()
{

    //CYCLE DETECTION IN UNDIRECTED GRAPH USING DFS

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

    if (isCycle(V, graph))
    {
        cout << "CYCLE IS PRESENT" << endl;
    }
    else
    {
        cout << "CYCLE IS NOT PRESENT" << endl;
    }
}
