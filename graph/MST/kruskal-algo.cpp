#include <bits/stdc++.h>
using namespace std;

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
  int solvePrims(int V, vector<vector<int>> adj[])
  {
    vector<int> v(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    int res = 0;
    while (!pq.empty())
    {
      int node = pq.top().second;
      int wei = pq.top().first;

      pq.pop();

      if (v[node] == 1)
        continue;

      v[node] = 1;
      res += wei;

      for (auto it : adj[node])
      {
        int nei = it[0];
        int dis = it[1];
        if (!v[nei])
        {
          pq.push({dis, nei});
        }
      }
    }
    return res;
  }

  int solveKruskal(int V, vector<vector<int>> adj[])
  {
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < adj[i].size(); j++)
      {
        edges.push_back({adj[i][j][1], {i, adj[i][j][0]}});
      }
    }

    sort(edges.begin(), edges.end());
    DisJoint ds(V);
    int mstW = 0;

    for (int i = 0; i < edges.size(); i++)
    {
      int wei = edges[i].first;
      int u = edges[i].second.first;
      int v = edges[i].second.second;

      if (ds.findUParent(u) != ds.findUParent(v))
      {
        mstW += wei;
        ds.doUnionbysize(u, v);
      }
    }
    return mstW;
  }
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    // code here
    // return solvePrims(V,adj;
    return solveKruskal(V, adj);
  }
};