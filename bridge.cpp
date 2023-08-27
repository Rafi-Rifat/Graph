#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
int timer = 1;
int tin[N];
int low[N];
vector<vector<int>> bridges;
void dfs(int node, int parent)
{
    vis[node] = true;
    tin[node] = low[node] = timer;
    timer++;
    for (int child : graph[node])
    {
        if (child == parent)
            continue;
        if (!vis[child])
        {
            dfs(child, node);
            low[node] = min(low[child], low[node]);
            if (low[child] > tin[node])
            {
                bridges.push_back({child, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[child]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    for (auto it : bridges)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    return 0;
}