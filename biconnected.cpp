#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list representation of the graph
int n;                   // Number of vertices
vector<int> tin, low;
int timer = 0;

vector<pair<int, int>> biconnectedComponents;
stack<pair<int, int>> st;

void dfs(int v, int p = -1)
{
    tin[v] = low[v] = timer++;
    for (int u : adj[v])
    {
        if (u == p)
            continue;
        if (tin[u] == -1)
        {
            st.push({v, u});
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] >= tin[v])
            {
                vector<pair<int, int>> component;
                while (!st.empty() && st.top() != make_pair(v, u))
                {
                    component.push_back(st.top());
                    st.pop();
                }
                component.push_back({v, u});
                biconnectedComponents.push_back(component);
            }
        }
        else
        {
            low[v] = min(low[v], tin[u]);
            if (tin[u] < tin[v])
                st.push({v, u});
        }
    }
}

int main()
{
    cin >> n;
    adj.resize(n);
    tin.assign(n, -1);
    low.assign(n, -1);

    int m;
    cin >> m; // Number of edges
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
    {
        if (tin[i] == -1)
        {
            dfs(i);
            if (!st.empty())
            {
                vector<pair<int, int>> component;
                while (!st.empty())
                {
                    component.push_back(st.top());
                    st.pop();
                }
                biconnectedComponents.push_back(component);
            }
        }
    }

    // Print biconnected components
    cout << "Biconnected Components:\n";
    for (const vector<pair<int, int>> &component : biconnectedComponents)
    {
        for (const pair<int, int> &edge : component)
        {
            cout << edge.first << " - " << edge.second << " ";
        }
        cout << "\n";
    }

    return 0;
}
