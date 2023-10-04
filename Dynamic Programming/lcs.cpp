#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[100][100];
int lcs(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // remove last 1 character from s1
    int ans = lcs(i - 1, j, s1, s2);
    // remove last 1 character from s2
    ans = max(ans, lcs(i, j - 1, s1, s2));
    // remove last 1 character from both s1 ans s2
    ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));
    return dp[i][j] = ans;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    cout << lcs(i, j, s1, s2) << endl;

    return 0;
}