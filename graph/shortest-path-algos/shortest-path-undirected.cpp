#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
  {
    // code here
    vector<int> v(N, 0);
    vector<int> adj[N];

    for (int i = 0; i < M; i++)
    {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<pair<int, int>> q;

    q.push({src, 0});
    v[src] = 1;
    vector<int> res(N, INT_MAX);
    int cnt = 1;
    res[src] = 0;

    while (!q.empty())
    {

      int node = q.front().first;
      int dis = q.front().second;
      q.pop();

      for (auto it : adj[node])
      {
        if (!v[it])
        {
          v[it] = 1;
          res[it] = dis + 1;
          q.push({it, dis + 1});
        }
        else
        {
          res[it] = min(res[it], dis + 1);
        }
      }
    }

    for (int i = 0; i < N; i++)
    {
      if (res[i] == INT_MAX)
        res[i] = -1;
    }
    return res;
  }
};