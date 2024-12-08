#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int optimal(int n)
  {
    int left = 1;
    int right = 1;

    for (int i = 2; i <= n; i++)
    {
      int t = right;
      right = left + right;
      left = t;
    }
    return right;
  }
  int tabulation(vector<int> &dp, int n)
  {
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
  int solve(vector<int> &dp, int n)
  {
    if (n == 0 || n == 1)
      return dp[n] = 1;

    if (dp[n] != -1)
      return dp[n];
    return dp[n] = solve(dp, n - 1) + solve(dp, n - 2);
  }
  int climbStairs(int n)
  {
    vector<int> dp(n + 1, -1);
    // return solve(dp,n);
    return tabulation(dp, n);
    // return optimal(n);
  }
};