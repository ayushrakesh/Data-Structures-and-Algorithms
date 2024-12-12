#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int ind, int target, vector<int> arr, vector<vector<int>> &dp)
  {
    int n = arr.size();
    // if (target == 0) return 1;
    if (ind == 0)
    {
      if (target == 0 && arr[0] == 0)
        return 2;
      // return (target == arr[0]);
      if (target == 0 || target == arr[0])
        return 1;
      return 0;
    }

    if (dp[ind][target] != -1)
      return dp[ind][target];

    int pick = 0;
    if (target >= arr[ind])
    {
      pick = solve(ind - 1, target - arr[ind], arr, dp);
    }
    int notpick = solve(ind - 1, target, arr, dp);

    return dp[ind][target] = (pick + notpick);
  }

  void tab(int ind, int target, vector<int> arr, vector<vector<int>> &dp)
  {

    for (int i = 0; i <= target; i++)
    {
      dp[0][i] = 0;
    }
    dp[0][0] = 1;
    dp[0][arr[0]] = 1;
    if (arr[0] == 0)
      dp[0][0] = 2;

    for (int i = 1; i <= ind; i++)
    {
      for (int j = 0; j <= target; j++)
      {
        if (j >= arr[i])
          dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i]]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
  }

  int countPartitions(vector<int> &arr, int d)
  {
    // Code here
    int n = arr.size();
    int sum = 0;
    for (auto it : arr)
    {
      sum += it;
    }
    int t = (sum - d) / 2;
    if ((sum - d) % 2 == 1 || (sum - d) < 0)
      return 0;
    vector<vector<int>> dp(n, vector<int>(t + 1, -1));
    // return solve(n-1, t, arr,dp);
    tab(n - 1, t, arr, dp);
    ;
    return dp[n - 1][t];
  }
};