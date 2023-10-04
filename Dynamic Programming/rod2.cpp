#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace chrono;

int rodcut(int len, vector<int> &dpArray)
{
    vector<int> memoization(len + 1, 0);
    for (int i = 1; i <= len; i++)
    {
        int max_profit = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            max_profit = max(max_profit, dpArray[j] + memoization[i - j]);
        }
        memoization[i] = max_profit;
    }
    return memoization[len];
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

    auto start = high_resolution_clock::now();

    int max_profit = rodcut(n, dpArray);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << max_profit << endl;
    cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
}