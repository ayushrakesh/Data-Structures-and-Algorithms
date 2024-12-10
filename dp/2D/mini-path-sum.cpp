#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int r, int c, vector<vector<int>> &grid,
            vector<vector<int>> &dp)
  {
    if (r == 0 && c == 0)
      return dp[r][c] = grid[0][0];
    if (r < 0 || c < 0)
      return 1e8;

    if (dp[r][c] != -1)
      return dp[r][c];
    int left = solve(r, c - 1, grid, dp);
    int top = solve(r - 1, c, grid, dp);

    return dp[r][c] = min(left + grid[r][c], top + grid[r][c]);
  }

  int tab(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
  {
    dp[0][0] = grid[0][0];
    for (int i = 1; i <= r; i++)
    {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int i = 1; i <= c; i++)
    {
      dp[0][i] = grid[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i <= r; i++)
    {
      for (int j = 1; j <= c; j++)
      {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[r][c];
  }

  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // return solve(m-1,n-1,grid,dp);
    return tab(m - 1, n - 1, grid, dp);
  }
};