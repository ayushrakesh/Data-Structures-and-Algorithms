#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int brute(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
  {
    int n = grid.size();
    int m = grid[0].size();
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
      return -1e8;
    if (i == n - 1)
    {
      if (j1 == j2)
        return dp[i][j1][j2] = grid[i][j1];
      else
      {
        return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
      }
    }

    if (dp[i][j1][j2] != -1)
      return dp[i][j1][j2];

    vector<int> d = {-1, 0, 1};

    int maxi = -1e8;
    for (auto a : d)
    {
      for (auto b : d)
      {
        if (j1 != j2)
          maxi = max(maxi, brute(i + 1, j1 + a, j2 + b, grid, dp) + grid[i][j1] + grid[i][j2]);
        else
          maxi = max(maxi, brute(i + 1, j1 + a, j2 + b, grid, dp) + grid[i][j2]);
      }
    }
    return dp[i][j1][j2] = maxi;
  }

  int solve(int n, int m, vector<vector<int>> &grid)
  {
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return brute(0, 0, m - 1, grid, dp);
  }
};