#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int sum = 0;
vector<pair<int, int>> adj[N];
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
        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour.first])
                pq.push({neighbour.second, neighbour.first});
        }
    }
}
int main()
{
    int n, m;

    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    mst();
    cout << sum << endl;
    return 0;
}