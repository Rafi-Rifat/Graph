#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
int level[N];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty())
    {
        int curr_vertex = q.front();
        q.pop();
        cout << curr_vertex << " ";
        for (int child : graph[curr_vertex])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[curr_vertex] + 1;
            }
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
    bfs(1);
    cout << endl;
    cout << "The levels of each vertex are :" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << level[i] << endl;
    }
    return 0;
}