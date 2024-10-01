#include <bits/stdc++.h>
using namespace std;
vector<int> solveBFS(vector<int> adj[], vector<int> &visited, int n, int m)
{
  queue<int> q;
  vector<int> res;
  q.push(1);
  visited[1] = 1;

  while (!q.empty())
  {
    int node = q.front();
    res.push_back(node);
    q.pop();

    for (int i = 0; i < adj[node].size(); i++)
    {
      if (!visited[i])
      {
        visited[i] = 1;
        q.push(adj[node][i]);
      }
    }
  }
  return res;
}
int main()
{
  int n = 8;
  int m = 8;
  vector<int> adj[n + 1];

  for (int i = 0; i < n + 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> visited(n + 1, 0);

  vector<int> res = solveBFS(adj, visited, n, m);

  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}