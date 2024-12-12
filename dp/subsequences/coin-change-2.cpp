#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind, int target, vector<int> arr, vector<vector<int>> &dp)
  {
    int n = arr.size();
    if (ind == 0)
    {
      if (target % arr[ind] == 0)
        return 1;
      else
        return 0;
    }

    if (dp[ind][target] != -1)
      return dp[ind][target];

    int pick = 0;
    if (target >= arr[ind])
    {
      pick = solve(ind, target - arr[ind], arr, dp);
    }
    int notpick = solve(ind - 1, target, arr, dp);

    return dp[ind][target] = (pick + notpick);
    // return min(pick , notpick);
  }
  long long tab(int ind, int target, vector<int> &arr, vector<vector<long long>> &dp)
  {
    int n = arr.size();
    for (int i = 0; i <= target; i++)
    {
      if (i % arr[0] == 0)
      {
        dp[0][i] = 1;
      }
      else
        dp[0][i] = 0;
    }
    const long long MOD = 1e9 + 7;
    for (int i = 1; i <= ind; i++)
    {
      for (int j = 0; j <= target; j++)
      {
        if (arr[i] <= j)
        {
          dp[i][j] = (dp[i - 1][j] + dp[i][j - arr[i]]) % MOD;
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[ind][target] % MOD;
  }
  int coinChange(vector<int> &coins, int amount)
  {
    int n = coins.size();
    vector<vector<long long>> dp(n, vector<long long>(amount + 1, -1));
    long long res = tab(n - 1, amount, coins, dp);
    // return solve(n-1, amount, coins, dp);
    // if (res == 1e8) return -1;
    return res;
  }
  int change(int amount, vector<int> &coins)
  {
    return coinChange(coins, amount);
  }
};