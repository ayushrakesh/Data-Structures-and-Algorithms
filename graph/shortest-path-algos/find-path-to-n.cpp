#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
  {
    // Code here
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
      adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
      adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    vector<int> res(n + 1, INT_MAX);
    vector<int> parent(n + 1, 0);

    for (int i = 0; i < n + 1; i++)
    {
      parent[i] = i;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    res[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
      int node = pq.top().second;
      int dis = pq.top().first;
      pq.pop();

      for (auto it : adj[node])
      {
        int nei = it.first;
        int wei = it.second;

        if (dis + wei < res[nei])
        {
          res[nei] = wei + dis;
          pq.push({res[nei], nei});

          parent[nei] = node;
        }
      }
    }
    int dis = res[n];
    vector<int> path;

    int node = n;
    while (parent[node] != node)
    {
      path.push_back(node);
      node = parent[node];
    }

    path.push_back(1);
    path.push_back(dis);
    reverse(path.begin(), path.end());
    return path;
  }
};