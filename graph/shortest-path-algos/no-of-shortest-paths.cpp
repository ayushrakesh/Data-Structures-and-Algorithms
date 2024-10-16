#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countPaths(int n, vector<vector<int>> &roads)
  {
    vector<pair<long long, long long>> adj[n];

    for (int i = 0; i < roads.size(); i++)
    {
      adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
      adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    vector<long long> res(n, 1e9);
    vector<long long> ways(n, 0);

    res[0] = 0;
    ways[0] = 1;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    pq.push({0, 0});
    int mod = (int)(1e9 + 7);

    while (!pq.empty())
    {
      long long node = pq.top().second;
      long long dis = pq.top().first;
      pq.pop();

      for (auto it : adj[node])
      {
        long long nei = it.first;
        long long wei = it.second;

        if (wei + dis < res[nei])
        {
          res[nei] = wei + dis;
          pq.push({res[nei], nei});
          ways[nei] = ways[node];
        }
        else if ((wei + dis) == res[nei])
        {
          ways[nei] = (ways[nei] + ways[node]) % mod;
        }
      }
    }
    return ways[n - 1] % mod;
  }
};