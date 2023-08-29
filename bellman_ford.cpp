#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, int>> graph[N];
bool vis[N];
vector<int> dist(N, INT_MAX);
bool flag = false;
int n, m;
void bellmanFord(int source)
{
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto child : graph[j])
            {
                int v_child = child.first,
                    weight = child.second;
                if (dist[j] != INT_MAX &&
                    dist[j] + weight < dist[v_child])
                    dist[v_child] = dist[j] + weight;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto child : graph[i])
        {
            int v_child = child.first,
                weight = child.second;
            if (dist[i] != INT_MAX && dist[i] + weight < dist[v_child])
            {
                flag = true;
                return;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    bellmanFord(0);
    if (flag)
    {
        cout << "cycle\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
        cout << i << " " << ((dist[i] == INT_MAX) ? -1 : dist[i]) << endl;
    return 0;
}