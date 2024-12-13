#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind, int target, vector<int> val, vector<vector<int>> &dp)
  {
    if (ind == 0)
    {
      if (1 <= target)
        return val[ind] * (target / 1);
      return 0;
    }

    if (dp[ind][target] != -1)
      return dp[ind][target];

    int nottake = solve(ind - 1, target, val, dp);
    int take = INT_MIN;
    if ((ind + 1) <= target)
    {
      take = val[ind] + solve(ind, target - (ind + 1), val, dp);
    }
    return dp[ind][target] = max(nottake, take);
  }
  int tab(int ind, int target, vector<int> val, vector<vector<int>> &dp)
  {
    for (int i = 0; i <= target; i++)
    {
      if (i >= 1)
        dp[0][i] = val[0] * (i / 1);
      else
        dp[0][i] = 0;
    }

    for (int i = 1; i <= ind; i++)
    {
      for (int j = 0; j <= target; j++)
      {
        int nottake = dp[i - 1][j];
        int take = INT_MIN;
        if ((i + 1) <= j)
          take = val[i] + dp[i][j - (i + 1)];

        dp[i][j] = max(nottake, take);
      }
    }
    return dp[ind][target];
  }
  int cutRod(vector<int> &price)
  {
    // code here
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return tab(n - 1, n, price, dp);
  }
};