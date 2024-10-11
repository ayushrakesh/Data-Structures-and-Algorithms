#include <bits/stdc++.h>
using namespace std;

vector<int> solveSet(int V, vector<vector<int>> adj[], int S)
{
  vector<int> res(V, INT_MAX);
  set<pair<int, int>> s;
  s.insert({0, S});
  res[S] = 0;

  while (!s.empty())
  {
    auto ite = *(s.begin());
    int node = ite.second;
    int dis = ite.first;

    s.erase(ite);

    for (auto it : adj[node])
    {
      int nei = it[0];
      int wei = it[1];

      if (res[nei] == INT_MAX)
      {
        res[nei] = wei + res[node];
        s.insert({res[nei], nei});
      }
      else
      {
        if (wei + res[node] < res[nei])
        {
          s.erase({res[nei], nei});
          res[nei] = wei + res[node];
          s.insert({res[nei], nei});
        }
      }
    }
  }
  return res;
}
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
  queue<int> q;

  q.push({src});
  v[src] = 1;
  vector<int> res(N, INT_MAX);
  // int cnt=1;
  res[src] = 0;

  while (!q.empty())
  {

    int node = q.front();
    // int dis=q.front().second;
    q.pop();

    for (auto it : adj[node])
    {
      if (!v[it])
      {
        v[it] = 1;
        q.push({it});
        res[it] = res[node] + 1;
      }
      else
      {
        res[it] = min(res[it], res[node] + 1);
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