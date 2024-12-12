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

    tab(n - 1, t, arr, dp);

    return dp[n - 1][t];
  }
  // int fun(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
  //     if (ind == 0) {
  //         if (nums[0] == target && target == 0)
  //             return 2;
  //         if (abs(target) == nums[ind])
  //             return 1;
  //         return 0;
  //     }

  //     int pos = fun(ind - 1, target - nums[ind], nums);
  //     int neg = fun(ind - 1, target + nums[ind], nums);

  //     return pos + neg;
  // }

  int findTargetSumWays(vector<int> &nums, int target)
  {
    return countPartitions(nums, target);
  }
};