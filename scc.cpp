// Only applicable for directed graph
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
vector<int> g_tranpose[N];
bool vis[N];
bool vis_transpose[N];

stack<int> st;
void dfs(int node)
{
    vis[node] = true;
    for (int child : g[node])
    {

        if (vis[child])
            continue;
        dfs(child);
    }
    st.push(node);
}
void dfs_transpose(int node)
{
    vis_transpose[node] = true;
    cout << node << " ";
    for (int child : g_tranpose[node])
    {

        if (vis_transpose[child])
            continue;
        dfs_transpose(child);
    }
}
int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g_tranpose[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    int cnt = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis_transpose[node])
        {
            cnt++;
            dfs_transpose(node);
            cout << endl;
        }
    }
    cout << "No of strongly connected components are: " << cnt << endl;

    return 0;
}
