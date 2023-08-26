#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
void dfs(int vertex)
{
    vis[vertex] = true;
    cout << vertex << " ";
    for (int child : graph[vertex])
    {
        if (vis[child])
            continue;
        dfs(child);
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
    int cnt = 0;
    cout << "Connected components are :\n";
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i);
            cout << endl;
        }
    }
    cout << "No of connected components : " << cnt << endl;
    return 0;
}
