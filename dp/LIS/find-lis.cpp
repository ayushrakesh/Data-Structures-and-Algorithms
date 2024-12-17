#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int last, int ind, vector<int> nums, vector<vector<int>> &dp)
  {
    if (ind < 0)
      return 0;
    if (dp[ind][last + 1] != -1)
      return dp[ind][last + 1];
    int take = 0;
    if (last == -1 || nums[ind] < nums[last])
      take = 1 + solve(ind, ind - 1, nums, dp);
    int nottake = solve(last, ind - 1, nums, dp);
    return dp[ind][last + 1] = max(take, nottake);
  }

  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(-1, n - 1, nums, dp);
  }
};