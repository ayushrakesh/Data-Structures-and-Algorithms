#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  class DisJoint
  {

    vector<int> rank;
    vector<int> parent;
    vector<int> size;

  public:
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
  int removeStones(vector<vector<int>> &stones)
  {
    int n = stones.size();
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < n; i++)
    {
      maxRow = max(maxRow, stones[i][0]);
      maxCol = max(maxCol, stones[i][1]);
    }
    DisJoint ds(maxRow + 1 + maxCol + 1);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      int row = stones[i][0];
      int col = stones[i][1] + 1 + maxRow;
      ds.doUnionbysize(row, col);
      mp[row] = 1;
      mp[col] = 1;
    }
    int cnt = 0;
    for (auto it : mp)
    {
      if (ds.findUParent(it.first) == it.first)
      {
        cnt++;
      }
    }

    return n - cnt;
  }
};