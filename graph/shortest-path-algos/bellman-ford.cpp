#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /*  Function to implement Bellman Ford
   *   edges: vector of vectors which represents the graph
   *   S: source vertex to start traversing graph with
   *   V: number of vertices
   */
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
  {
    // Code here
    int max = 1e8;
    vector<int> res(V, max);
    res[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
      for (int j = 0; j < edges.size(); j++)
      {
        if (res[edges[j][0]] != max && edges[j][2] + res[edges[j][0]] < res[edges[j][1]])
        {
          res[edges[j][1]] = edges[j][2] + res[edges[j][0]];
        }
      }
    }

    for (int i = 0; i < edges.size(); i++)
    {
      if (res[edges[i][0]] != max && edges[i][2] + res[edges[i][0]] < res[edges[i][1]])
      {
        return {-1};
      }
    }
    return res;
  }
};
