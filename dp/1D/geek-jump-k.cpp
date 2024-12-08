#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int solve(vector<int> &arr, int k, int ind)
  {
    if (ind == 0)
      return 0;

    int t = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
      if (ind - i >= 0)
      {
        t = min(t, solve(arr, k, ind - i) + abs(arr[ind] - arr[ind - i]));
      }
    }
    return t;
  }
  int memo(vector<int> &arr, int k, int ind, vector<int> &dp)
  {
    if (ind == 0)
      return dp[ind] = 0;

    if (dp[ind] != -1)
      return dp[ind];
    int t = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
      if (ind - i >= 0)
      {
        t = min(t, memo(arr, k, ind - i, dp) + abs(arr[ind] - arr[ind - i]));
      }
    }
    return dp[ind] = t;
  }
  int tabulation(vector<int> &arr, int k, int ind, vector<int> &dp)
  {
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);

    for (int i = 2; i <= ind; i++)
    {
      int t = INT_MAX;
      for (int j = 1; j <= (k); j++)
      {
        if (i - j >= 0)
        {
          t = min(t, dp[i - j] + abs(arr[i] - arr[i - j]));
        }
      }
      dp[i] = t;
    }
    return dp[ind];
  }
  int minimizeCost(int k, vector<int> &arr)
  {
    // Code here
    int n = arr.size();
    // return solve(arr,k,n-1);
    vector<int> dp(n + 1, -1);
    // return memo(arr,k,n-1,dp);
    if (n == 1)
      return 0;
    return tabulation(arr, k, n - 1, dp);
  }
};