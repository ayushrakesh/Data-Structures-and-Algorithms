#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid)
  {
    if (grid[0][0] == 1)
      return -1;

    int n = grid.size();
    vector<vector<int>> res(n, vector<int>(n, INT_MAX));
    queue<pair<int, pair<int, int>>> q;

    q.push({0, {0, 0}});
    res[0][0] = 0;

    while (!q.empty())
    {
      int a = q.front().second.first;
      int b = q.front().second.second;
      int dis = q.front().first;
      q.pop();

      vector<int> row = {-1, -1, 0, 1, 1, 1, 0, -1};
      vector<int> col = {0, 1, 1, 1, 0, -1, -1, -1};

      for (int i = 0; i < 8; i++)
      {
        int nrow = row[i] + a;
        int ncol = col[i] + b;

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
            !grid[nrow][ncol] && (dis + 1 < res[nrow][ncol]))
        {
          res[nrow][ncol] = dis + 1;
          q.push({dis + 1, {nrow, ncol}});
        }
      }
    }

    if (res[n - 1][n - 1] == INT_MAX)
      return -1;
    return res[n - 1][n - 1] + 1;
  }
};