#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
queue<int> q;
void bfs(int vertex, int n)
{
    vis[vertex] = true;
    q.push(vertex);
    for (int i = vertex; i <= n; i++)
    {
        cout << i << "-> ";
        for (auto it : graph[i])
        {
            cout << it << " ";
        }
        cout << endl;
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

    return 0;
}