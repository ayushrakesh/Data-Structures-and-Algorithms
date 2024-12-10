#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int r, int c, vector<vector<int>> &dp)
  {
    if (r == 0 && c == 0)
      return dp[r][c] = 1;
    if (r < 0 || c < 0)
      return 0;

    if (dp[r][c] != -1)
      return dp[r][c];
    return dp[r][c] = solve(r - 1, c, dp) + solve(r, c - 1, dp);
  }
  int tab(int r, int c, vector<vector<int>> &dp)
  {
    dp[0][0] = 1;
    for (int i = 0; i <= r; i++)
      dp[i][0] = 1;
    for (int i = 0; i <= c; i++)
      dp[0][i] = 1;

    for (int i = 1; i <= r; i++)
    {
      for (int j = 1; j <= c; j++)
      {
        //    if(i==0 && j==0)continue;
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[r][c];
  }
  int optimal(int r, int c)
  {
    vector<int> t(c + 1, 0);

    for (int i = 0; i <= r; i++)
    {
      vector<int> u(c + 1, 0);
      for (int j = 0; j <= c; j++)
      {
        if (i == 0 && j == 0)
          u[0] = 1;
        else if (j == 0)
          u[0] = t[0];
        else
        {
          u[j] = t[j] + u[j - 1];
        }
      }
      t = u;
    }
    return t[c];
  }
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // return solve(m-1,n-1,dp);
    // return tab(m-1,n-1,dp);
    return optimal(m - 1, n - 1);
  }
};