#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];
vector<int> vis(N, 0);
vector<int> distTo(N, INF);
void dijkstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distTo[source] = 0;
    pq.push(make_pair(0, source)); // (dist,source)
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        vector<pair<int, int>>::iterator it;
        for (it = g[node].begin(); it != g[node].end(); it++)
        {
            int next = it->first;
            int nextDist = it->second;
            if (distTo[next] > distTo[node] + nextDist)
            {
                distTo[next] = distTo[node] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
}

int main()
{
    int n, m, source = 1;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijkstra(1);
    cout << "The distances from source " << source << " are : \n";
    for (int i = 1; i <= n; i++)
        cout << distTo[i] << " ";
    cout << "\n";
    // return 0;
}