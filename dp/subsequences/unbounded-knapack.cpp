#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind, int target, vector<int> wt, vector<int> val, vector<vector<int>> &dp)
  {
    if (ind == 0)
    {
      if (wt[ind] <= target)
        return val[ind] * (target / wt[ind]);
      return 0;
    }

    if (dp[ind][target] != -1)
      return dp[ind][target];

    int nottake = solve(ind - 1, target, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= target)
    {
      take = val[ind] + solve(ind, target - wt[ind], wt, val, dp);
    }
    return dp[ind][target] = max(nottake, take);
  }
  int tab(int ind, int target, vector<int> wt, vector<int> val, vector<vector<int>> &dp)
  {
    for (int i = 0; i <= target; i++)
    {
      if (i >= wt[0])
        dp[0][i] = val[0] * (i / wt[0]);
      else
        dp[0][i] = 0;
    }

    for (int i = 1; i <= ind; i++)
    {
      for (int j = 0; j <= target; j++)
      {
        int nottake = dp[i - 1][j];
        int take = INT_MIN;
        if (wt[i] <= j)
          take = val[i] + dp[i][j - wt[i]];

        dp[i][j] = max(nottake, take);
      }
    }
    return dp[ind][target];
  }
  int knapSack(vector<int> &val, vector<int> &wt, int capacity)
  {
    // code here
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // return solve(n-1,capacity,wt,val,dp);
    return tab(n - 1, capacity, wt, val, dp);
  }
};