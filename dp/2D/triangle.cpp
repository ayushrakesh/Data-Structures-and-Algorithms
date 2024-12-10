#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int r, int c, vector<vector<int>> &triangle,
            vector<vector<int>> &dp)
  {
    if (r == 0 && c == 0)
      return dp[r][c] = triangle[r][c];
    if (r < 0 || c < 0)
      return INT_MAX;
    if (dp[r][c] != -1)
      return dp[r][c];
    int top = INT_MAX;
    if (r != c)
    {
      top = solve(r - 1, c, triangle, dp);
    }
    int left = solve(r - 1, c - 1, triangle, dp);

    return dp[r][c] = min(top, left) + triangle[r][c];
  }
  void tab(int r, vector<vector<int>> &triangle, vector<vector<int>> &dp)
  {

    dp[0][0] = triangle[0][0];

    for (int i = 1; i <= r; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        if (j == 0)
        {
          dp[i][0] = dp[i - 1][0] + triangle[i][0];
        }
        else if (i == j)
        {
          dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
        }
      }
    }
    for (int i = 2; i <= r; i++)
    {
      for (int j = 1; j < i; j++)
      {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
      }
    }
  }
  int minimumTotal(vector<vector<int>> &triangle)
  {
    int m = triangle.size();

    vector<vector<int>> dp(m, vector<int>(m, -1));
    int res = INT_MAX;
    tab(m - 1, triangle, dp);
    for (int i = 0; i < m; i++)
    {
      // dp[m-1][i]=solve(m - 1, i, triangle,dp);
      res = min(res, dp[m - 1][i]);
    }
    return res;
  }
};