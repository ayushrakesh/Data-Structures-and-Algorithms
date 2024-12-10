#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int r, int c, vector<vector<int>> matrix,
            vector<vector<int>> &dp)
  {
    int n = matrix.size();
    if (c >= 0 && c < n && r == (n - 1))
      return dp[r][c] = matrix[r][c];
    if (r < 0 || c < 0 || r >= n || c >= n)
      return INT_MAX;

    if (dp[r][c] != -1)
      return dp[r][c];

    int left = solve(r + 1, c - 1, matrix, dp);
    int right = solve(r + 1, c + 1, matrix, dp);
    int down = solve(r + 1, c, matrix, dp);

    return dp[r][c] = min(left, min(right, down)) + matrix[r][c];
  }

  void tab(vector<vector<int>> matrix, vector<vector<int>> &dp)
  {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
      dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (j == 0)
        {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
          continue;
        }
        if (j == n - 1)
        {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
          continue;
        }
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i][j];
      }
    }
  }

  int minFallingPathSum(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int res = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    tab(matrix, dp);
    for (int i = 0; i < n; i++)
    {
      // dp[0][i] = solve(0, i, matrix, dp);
      res = min(res, dp[n - 1][i]);
    }
    return res;
  }
};