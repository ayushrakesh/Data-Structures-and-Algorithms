#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool solve(int ind, int target, vector<int> arr, vector<vector<int>> &dp)
  {
    int n = arr.size();
    if (target == 0)
      return true;
    if (ind == 0)
      return target == arr[ind];

    if (dp[ind][target] != -1)
      return dp[ind][target];

    bool pick = false;
    if (target >= arr[ind])
    {
      pick = solve(ind - 1, target - arr[ind], arr, dp);
    }
    bool notpick = solve(ind - 1, target, arr, dp);

    return dp[ind][target] = (pick || notpick);
  }

  void tab(int ind, int target, vector<int> arr, vector<vector<int>> &dp)
  {
    for (int i = 0; i <= target; i++)
    {
      dp[0][i] = 0;
    }
    if (arr[0] <= target)
      dp[0][arr[0]] = 1;

    for (int i = 0; i <= ind; i++)
    {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= ind; i++)
    {
      for (int j = 1; j <= target; j++)
      {
        if (j >= arr[i])
          dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i]]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
  }

  bool isSubsetSum(vector<int> &arr, int target)
  {
    // code here]
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    // return solve(n-1,target, arr,dp);
    tab(n - 1, target, arr, dp);
    return dp[n - 1][target];
  }
};