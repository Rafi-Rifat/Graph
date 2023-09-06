#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int sum = 0;
vector<pair<int, int>> g[N];
bool vis[N];
void mst()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int weight = top.first;
        int node = top.second;
        if (vis[node])
            continue;
        vis[node] = 1;
        sum += weight;
        for (auto child : g[node])
        {
            if (!vis[child.first])
                pq.push({child.second, child.first});
        }
    }
}
int main()
{
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    mst();
    cout << sum << endl;
    return 0;
}