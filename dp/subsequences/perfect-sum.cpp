#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
    tab(n - 1, target, arr, dp);
    return dp[n - 1][target];
  }
  bool canPartition(vector<int> &nums)
  {
    int n = nums.size();
    int sum = 0;
    for (auto it : nums)
    {
      sum += it;
    }
    if (sum % 2 == 1)
      return false;
    vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));
    tab(n - 1, sum / 2, nums, dp);
    return dp[n - 1][sum / 2];
  }
};