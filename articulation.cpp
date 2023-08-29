#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
int timer = 1;
int tin[N];
int low[N];
int mark[N];
void dfs(int node, int parent)
{
    vis[node] = true;
    tin[node] = low[node] = timer;
    timer++;
    int cnt = 0;
    for (int child : graph[node])
    {
        if (child == parent)
            continue;
        if (!vis[child])
        {
            dfs(child, node);
            low[node] = min(low[child], low[node]);
            if (low[child] >= tin[node] && parent != -1)
            {
                mark[node] = 1;
                cnt++;
            }
        }
        else
        {
            low[node] = min(low[node], low[child]);
        }
    }
    if (cnt > 1 && parent == -1)
        mark[node] = 1;
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
    for (int i = 1; i <= n; i++)
    {
        if (mark[i])
            cout << i << endl;
    }
    return 0;
}