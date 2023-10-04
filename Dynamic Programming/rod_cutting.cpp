#include <bits/stdc++.h>
using namespace std;
int dp[105];
int func(int len, int val[])
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int ans = 0;
    for (int len_to_cut = 1; len_to_cut <= len; len_to_cut++)
    {
        if (len - len_to_cut >= 0)
        {
            ans = max(ans, func(len - len_to_cut, val) + val[len_to_cut - 1]);
        }
    }
    return dp[len] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int len;
    cin >> len;
    int val[len];

    for (int i = 0; i < len; i++)
    {
        cin >> val[i];
    }
    cout << func(len, val);
    return 0;
}