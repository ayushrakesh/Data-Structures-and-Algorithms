#include <bits/stdc++.h>
using namespace std;
void solveDFS(int node, vector<int> adj[], vector<int> &visited, vector<int> &res)
{
  visited[node] = 1;
  res.push_back(node);

  for (int i = 0; i < adj[node].size(); i++)
  {
    if (!visited[adj[node][i]])
    {
      solveDFS(adj[node][i], adj, visited, res);
    }
  }
}
int main()
{
  int n = 8;
  int m = 8;
  vector<int> adj[n + 1];
  vector<int> visited(n + 1, 0);

  for (int i = 0; i < n + 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> res;
  solveDFS(0, adj, visited, res);

  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}