#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind, vector<int> prices, int buy, vector<vector<int>> &dp, int fee)
  {
    if (ind == prices.size())
      return 0;
    if (dp[ind][buy] != -1)
      return dp[ind][buy];
    if (buy)
    {
      return dp[ind][buy] = max(-prices[ind] + solve(ind + 1, prices, 0, dp, fee), solve(ind + 1, prices, 1, dp, fee));
    }
    return dp[ind][buy] = max(prices[ind] + solve(ind + 1, prices, 1, dp, fee) - fee, solve(ind + 1, prices, 0, dp, fee));
  }
  int tab(vector<int> prices, int buy, vector<vector<int>> &dp, int fee)
  {
    int n = prices.size();
    dp[n][0] = dp[n][1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = 0; j < 2; j++)
      {
        if (j == 1)
        {
          dp[i][j] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
        }
        else
          dp[i][j] = max(dp[i + 1][1] + prices[i] - fee, dp[i + 1][0]);
      }
    }
    return dp[0][1];
  }
  int maxProfit(vector<int> &prices, int fee)
  {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return tab(prices, 1, dp, fee);
  }
};