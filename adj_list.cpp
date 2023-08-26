#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
// vector<pair<int, int>> g[N];    for weighted undirected graph
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
    for (int i = 1; i <= n; i++)
    {
        cout << i << "-> ";
        for (auto it : graph[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}