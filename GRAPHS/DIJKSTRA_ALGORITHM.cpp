#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min Heap

int main()
{
    int V, E;
    cin >> V >> E;

    graph.resize(V + 1);
    for (int i = 0; i < E; i++)
    {
        int x, y, weight;
        cin >> x >> y >> weight;
        graph[x].push_back({y, weight});
        graph[y].push_back({x, weight});
    }

    int src = 1;

    int dis[V + 1];
    for (int i = 1; i <= V; i++)
    {
        dis[i] = INT_MAX;
    }

    pq.push({0, src});
    dis[src] = 0;

    while (pq.size() > 0)
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int node = p.second;
        for (auto it : graph[node])
        {
            if (dis[node] + it.second < dis[it.first])
            {
                dis[it.first] = dis[node] + it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}

