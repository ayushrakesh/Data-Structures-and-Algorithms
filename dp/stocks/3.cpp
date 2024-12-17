#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind, vector<int> prices, int buy, int t, vector<vector<vector<int>>> &dp)
  {
    if (t == 0)
      return 0;
    if (ind == prices.size())
      return 0;
    if (dp[ind][buy][t] != -1)
      return dp[ind][buy][t];
    if (buy)
    {
      return dp[ind][buy][t] = max(-prices[ind] + solve(ind + 1, prices, 0, t, dp), solve(ind + 1, prices, 1, t, dp));
    }
    return dp[ind][buy][t] = max(prices[ind] + solve(ind + 1, prices, 1, t - 1, dp), solve(ind + 1, prices, 0, t, dp));
  }

  int tab(vector<int> prices, int buy, vector<vector<vector<int>>> &dp)
  {
    int n = prices.size();
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= buy; j++)
      {
        dp[i][j][0] = 0;
      }
    }

    for (int j = 0; j <= buy; j++)
    {
      for (int k = 0; k <= 2; k++)
      {
        dp[n][j][k] = 0;
      }
    }

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = 0; j < 2; j++)
      {
        for (int k = 1; k <= 2; k++)
          if (j == 1)
          {
            dp[i][j][k] = max(dp[i + 1][0][k] - prices[i], dp[i + 1][1][k]);
          }
          else
            dp[i][j][k] = max(dp[i + 1][1][k - 1] + prices[i], dp[i + 1][0][k]);
      }
    }
    return dp[0][1][2];
  }

  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return tab(prices, 1, dp);
  }
};