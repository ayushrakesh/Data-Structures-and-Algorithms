#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /**
   * @param grid: a list of lists of integers
   * @return: return an integer, denote the number of distinct islands
   */
  void dfs(int a, int b, vector<vector<int>> &v, vector<vector<int>> &grid, vector<pair<int, int>> &u)
  {
    v[a][b] = 1;
    int m = grid.size();
    int n = grid[0].size();

    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
      int nrow = a + row[i];
      int ncol = b + col[i];

      if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !v[nrow][ncol] && grid[nrow][ncol])
      {
        u.push_back({nrow - a, ncol - b});
        dfs(nrow, ncol, v, grid, u);
      }
    }
  }
  int numberofDistinctIslands(vector<vector<int>> &grid)
  {
    // write your code here
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> v(m, vector<int>(n, 0));
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!v[i][j] && grid[i][j])
        {
          vector<pair<int, int>> u;
          u.push_back({0, 0});
          dfs(i, j, v, grid, u);
          s.insert(u);
        }
      }
    }
    return s.size();
  }
};