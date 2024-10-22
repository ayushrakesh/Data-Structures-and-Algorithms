#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class DisJoint
{
  vector<int> rank;
  vector<int> parent;

public:
  vector<int> size;
  DisJoint(int n)
  {
    rank.resize(n + 1, 0);
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int findUParent(int node)
  {
    if (node == parent[node])
    {
      return node;
    }
    parent[node] = findUParent(parent[node]);
    return parent[node];
  }
  void doUnionbyrank(int u, int v)
  {
    int pu = findUParent(u);
    int pv = findUParent(v);

    if (pu == pv)
      return;

    if (rank[pu] < rank[pv])
    {
      parent[pu] = pv;
    }
    else if (rank[pu] > rank[pv])
    {
      parent[pv] = pu;
    }
    else
    {
      parent[pu] = pv;
      rank[pv]++;
    }
  }
  void doUnionbysize(int u, int v)
  {
    int pu = findUParent(u);
    int pv = findUParent(v);

    if (pu == pv)
      return;

    if (size[pu] < size[pv])
    {
      parent[pu] = pv;
      size[pv] += size[pu];
    }
    else
    {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
};

class Solution
{

public:
  int largestIsland(vector<vector<int>> &grid)
  {
    int n = grid.size();
    DisJoint ds(n * n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};
        if (grid[i][j] == 1)
        {
          for (int k = 0; k < 4; k++)
          {
            int nrow = row[k] + i;
            int ncol = col[k] + j;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                grid[nrow][ncol])
            {
              int node1 = i * n + j;
              int node2 = nrow * n + ncol;
              ds.doUnionbysize(node1, node2);
            }
          }
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
        {
          set<int> s;
          vector<int> row = {-1, 0, 1, 0};
          vector<int> col = {0, 1, 0, -1};

          for (int k = 0; k < 4; k++)
          {
            int nrow = row[k] + i;
            int ncol = col[k] + j;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                grid[nrow][ncol])
            {
              int node = nrow * n + ncol;
              s.insert(ds.findUParent(node));
            }
          }
          int sizetotal = 0;
          for (auto it : s)
          {
            int parent = it;
            sizetotal += ds.size[parent];
          }
          sizetotal++;
          res = max(res, sizetotal);
        }
      }
    }

    for (int i = 0; i < (n * n); i++)
    {
      int parent = ds.findUParent(i);
      res = max(res, ds.size[parent]);
    }
    return res;
  }
};
