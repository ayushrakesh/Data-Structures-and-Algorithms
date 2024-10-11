#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int node, vector<int> &v, vector<pair<int, int>> adj[], stack<int> &st)
  {
    v[node] = 1;

    for (auto it : adj[node])
    {
      if (!v[it.first])
      {

        dfs(it.first, v, adj, st);
      }
    }
    st.push(node);
  }
  vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
  {
    // code here
    vector<int> v(N, 0);
    vector<pair<int, int>> adj[N];
    stack<int> st;

    for (int i = 0; i < M; i++)
    {
      adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    for (int i = 0; i < N; i++)
    {
      if (!v[i])
      {
        dfs(i, v, adj, st);
      }
    }

    vector<int> res(N, INT_MAX);

    res[src] = 0;

    while (!st.empty())
    {
      int node = st.top();
      st.pop();

      if (res[node] != INT_MAX)
      {
        for (auto it : adj[node])
        {
          if ((it.second + res[node]) < res[it.first])
          {
            res[it.first] = it.second + res[node];
          }
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