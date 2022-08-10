#include <bits/stdc++.h>
using namespace std;

bool checkForBipartite(int src, vector<int> graph[], int *color)
{

    queue<int> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if (color[node] == 1)
                    color[it] = 2;
                else
                    color[it] = 1;

                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<int> graph[], int V)
{
    int color[V + 1];
    for (int i = 1; i <= V; i++)
        color[i] = -1;

    for (int i = 1; i <= V; i++)
    {
        if (color[i] == -1)
        {
            if (!checkForBipartite(i, graph, color))
                return false;
        }
    }
    return true;
}

int main()
{

    //BIPARTITE GRAPH USING BFS

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

    if (isBipartite(graph, V))
    {
        cout << "GRAPH IS BIPARTITE" << endl;
    }
    else
    {
        cout << "GRAPH IS NOT BIPARTITE" << endl;
    }
}
