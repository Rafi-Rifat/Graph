#include <bits/stdc++.h>
using namespace std;
#include <chrono>
using namespace chrono;

int rodcut(int len, vector<int> &dpArray)
{
   if (len == 0)
      return 0;

   int max_profit = INT_MIN;

   for (int i = 1; i <= len; i++)
   {
      int currprofit = dpArray[i] + rodcut(len - i, dpArray);
      max_profit = max(max_profit, currprofit);
   }
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

   auto start = high_resolution_clock::now();

   int max_profit = rodcut(n, dpArray);

   auto stop = high_resolution_clock::now(); // Record the stop time
   auto duration = duration_cast<nanoseconds>(stop - start);

   cout << max_profit << endl;

   cout << "Execution time: " << duration.count() << " nanoseconds" << endl;
}