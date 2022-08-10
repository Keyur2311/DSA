#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int src, vector<int> graph[], bool *vis, bool *dfsVis)
{
    for (auto it : graph[src])
    {
        if (vis[it] == false)
        {
            vis[it] = true;
            dfsVis[it] = true;
            return checkForCycle(it, graph, vis, dfsVis);
        }
        else if(vis[it]==true && dfsVis[it]==true){
            return true;
        }
    }
    dfsVis[src] = false;

    return false;
}
bool isCycle(vector<int> graph[], int V)
{
    bool vis[V + 1] = {0};
    bool dfsVis[V + 1] = {0};

    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == false)
        {
            if (checkForCycle(i, graph, vis, dfsVis))
                return true;
        }
    }
    return false;
}
int main()
{

    // CYCLE DETECTION IN DIRECTED GRAPH USING DFS

    // TIME COMPLEXITY  :- O(V+E)
    // SPACE COMPLEXITY :- O(2V)
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

    if(isCycle(graph,V)){
        cout<<"CYCLE DETECTED"<<endl;
    }
    else{
        cout<<"CYCLE IS NOT PRESENT"<<endl;
    }
}
