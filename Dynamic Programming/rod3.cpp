#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace chrono;

int rodcut(int n, vector<int> &dpArray, vector<int> &memoization)
{
    if (n == 0)
        return 0;
    if (memoization[n] != -1)
    {
        return memoization[n];
    }

    int max_profit = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        int curprofit = dpArray[i] + rodcut(n - i, dpArray, memoization);
        max_profit = max(max_profit, curprofit);
    }

    memoization[n] = max_profit;
    return max_profit;
}
int main()
{
    int n;
    cin >> n;

    vector<int> dpArray(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> dpArray[i];
    }

    vector<int> memoization(n + 1, -1);
    auto start = high_resolution_clock::now();

    int max_profit = rodcut(n, dpArray, memoization);

    auto stop = high_resolution_clock::now(); // Record the stop time
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << max_profit << endl;

    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
}