#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find sum of weights of edges of the Minimum Spanning Tree.
  int spanningTree(int V, vector<vector<int>> adj[])
  {
    // code here
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
};