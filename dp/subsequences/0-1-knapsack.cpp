#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
int solve(int ind, int target, vector<int> weight, vector<int> value, vector<vector<int>> &dp)
{
  if (ind == 0)
  {
    if (target >= weight[0])
      return value[0];
    return 0;
  }
  if (dp[ind][target] != -1)
    return dp[ind][target];

  int nottake = solve(ind - 1, target, weight, value, dp);
  int take = INT_MIN;
  if (weight[ind] <= target)
  {
    take = value[ind] + solve(ind - 1, target - weight[ind], weight, value, dp);
  }
  return dp[ind][target] = max(nottake, take);
}
int tab(int ind, int target, vector<int> weight, vector<int> value, vector<vector<int>> &dp)
{

  for (int i = 0; i <= target; i++)
  {
    if (i >= weight[0])
      dp[0][i] = value[0];
    else
      dp[0][i] = 0;
  }
  for (int i = 1; i <= ind; i++)
  {
    for (int j = 0; j <= target; j++)
    {
      int take = INT_MIN;
      if (j >= weight[i])
      {
        take = value[i] + dp[i - 1][j - weight[i]];
      }
      dp[i][j] = max(dp[i - 1][j], take);
    }
  }
  return dp[ind][target];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  // Write your code here
  // int n=weight.size();
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  // return solve(n-1,maxWeight,weight,value,dp);
  return tab(n - 1, maxWeight, weight, value, dp);
}