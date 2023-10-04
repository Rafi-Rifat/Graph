#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> a(N);
int dp[N];
int func(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[i] > a[j])
        {
            ans = max(ans, func(j) + 1);
        }
    }
    return dp[i] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, func(i));
    }
    cout << ans << endl;
    return 0;
}