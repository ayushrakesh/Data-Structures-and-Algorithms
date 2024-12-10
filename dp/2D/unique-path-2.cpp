#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int r, int c, vector<vector<int>> &obstacleGrid,
            vector<vector<int>> &dp)
  {
    if ((r >= 0 && c >= 0) && obstacleGrid[r][c] == 1)
      return 0;
    if (r == 0 && c == 0)
      return dp[r][c] = 1;
    if (r < 0 || c < 0)
      return 0;
    if (dp[r][c] != -1)
      return dp[r][c];
    return dp[r][c] = solve(r - 1, c, obstacleGrid, dp) +
                      solve(r, c - 1, obstacleGrid, dp);
  }
  int tab(int r, int c, vector<vector<int>> &obstacleGrid,
          vector<vector<int>> &dp)
  {
    dp[0][0] = 1;
    bool p = false;
    for (int i = 0; i <= r; i++)
    {
      if (obstacleGrid[i][0] == 1)
      {
        p = true;
        dp[i][0] = 0;
      }
      if (!p)
        dp[i][0] = 1;
    }
    p = false;
    for (int i = 0; i <= c; i++)
    {
      if (obstacleGrid[0][i] == 1)
      {
        p = true;
        dp[0][i] = 0;
      }
      if (!p)
        dp[0][i] = 1;
    }

    for (int i = 1; i <= r; i++)
    {
      for (int j = 1; j <= c; j++)
      {
        if (obstacleGrid[i][j] == 1)
          dp[i][j] = 0;
        else
        {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[r][c];
  }
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, obstacleGrid, dp);
    return tab(m - 1, n - 1, obstacleGrid, dp);
  }
};