#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
bool dfs(int vertex, int parent)
{
    vis[vertex] = true;
    // cout << vertex << " ";
    bool isLoopExists = false;
    for (int child : graph[vertex])
    {
        if (vis[child] and child == parent)
            continue;
        if (vis[child])
            return true;
        isLoopExists |= dfs(child, vertex);
    }
    return isLoopExists;
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
    return 0;
}