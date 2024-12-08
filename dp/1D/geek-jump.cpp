#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(vector<int> &height, int ind)
  {
    if (ind == 0)
      return 0;
    if (ind == 1)
      return abs(height[0] - height[1]);

    return min(solve(height, ind - 2) + abs(height[ind] - height[ind - 2]), solve(height, ind - 1) + abs(height[ind] - height[ind - 1]));
  }
  int memo(vector<int> &height, vector<int> &dp, int ind)
  {
    if (ind == 0)
      return dp[ind] = 0;
    if (ind == 1)
      return dp[ind] = abs(height[0] - height[1]);

    if (dp[ind] != -1)
      return dp[ind];
    return dp[ind] = min(memo(height, dp, ind - 2) + abs(height[ind] - height[ind - 2]), memo(height, dp, ind - 1) + abs(height[ind] - height[ind - 1]));
  }
  int tabulation(vector<int> &height, int ind, vector<int> &dp)
  {
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);

    for (int i = 2; i <= ind; i++)
    {
      dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]), dp[i - 2] + abs(height[i] - height[i - 2]));
    }
    return dp[ind];
  }
  int optimal(vector<int> &height, int ind)
  {
    int left = 0;
    int right = abs(height[0] - height[1]);

    for (int i = 2; i <= ind; i++)
    {
      int t = right;
      right = min(left + abs(height[i] - height[i - 2]), t + abs(height[i] - height[i - 1]));
      left = t;
    }
    return right;
  }
  int minimumEnergy(vector<int> &height, int n)
  {
    // Code here
    // return solve(height,n-1);
    vector<int> dp(n + 1, -1);

    // return memo(height,dp,n-1);
    // return tabulation(height,n-1,dp);
    if (n == 1)
      return 0;
    return optimal(height, n - 1);
  }
};