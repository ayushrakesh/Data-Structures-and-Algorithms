#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(vector<int> &nums, int ind)
  {
    int n = nums.size();
    if (ind == (n - 1))
      return nums[ind];
    if (ind == n)
      return 0;

    return max(nums[ind] + solve(nums, ind + 2), solve(nums, ind + 1));
  }
  int memo(vector<int> &nums, int ind, vector<int> &dp)
  {
    int n = nums.size();

    if (ind == (n - 1))
      return dp[ind] = nums[n - 1];
    if (ind == n)
      return dp[ind] = 0;

    if (dp[ind] != -1)
      return dp[ind];

    return dp[ind] = max(nums[ind] + memo(nums, ind + 2, dp), memo(nums, ind + 1, dp));
  }
  int tabulation(vector<int> &nums, int ind, vector<int> &dp)
  {
    int n = nums.size();
    dp[n - 1] = nums[n - 1];
    dp[n] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
      dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[ind];
  }
  int optimal(vector<int> &nums, int ind)
  {
    int n = nums.size();
    int left = nums[n - 1];
    int right = 0;

    for (int i = n - 2; i >= 0; i--)
    {
      int t = left;
      left = max(nums[i] + right, t);
      right = t;
    }
    return left;
  }
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    // return solve(nums,0);
    // return memo(nums,0,dp);
    // return tabulation(nums,0,dp);
    return optimal(nums, 0);
  }
};