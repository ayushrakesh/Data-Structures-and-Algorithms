#include <bits/stdc++.h>
using namespace std;

class DisJoint
{

public:
  vector<int> rank;
  vector<int> parent;
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
    int pu = parent[u];
    int pv = parent[v];

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
    int pu = parent[u];
    int pv = parent[v];

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
  int makeConnected(int n, vector<vector<int>> &connections)
  {

    DisJoint ds(n);
    int extraedges = 0;
    for (int i = 0; i < connections.size(); i++)
    {
      if (ds.findUParent(connections[i][0]) == ds.findUParent(connections[i][1]))
      {
        extraedges++;
      }
      else
      {
        ds.doUnionbysize(connections[i][0], connections[i][1]);
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (ds.parent[i] == i)
        cnt++;
    }
    if (extraedges >= (cnt - 1))
    {
      return cnt - 1;
    }
    else
    {
      return -1;
    }
  }
};