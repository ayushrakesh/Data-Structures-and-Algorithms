#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  struct Compare
  {
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
      return a.first > b.first; // Min-heap (reverse order)
    }
  };
  void solve(vector<vector<int>> arr, vector<int> &res, int n, int k)
  {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> p;

    for (int i = 0; i < k; i++)
    {
      p.push({arr[i][0], {i, 0}});
    }

    while (!p.empty())
    {
      int top = p.top().first;
      int r = p.top().second.first;
      int c = p.top().second.second;

      p.pop();

      res.push_back(top);

      if (c < (k - 1))
      {
        p.push({arr[r][c + 1], {r, c + 1}});
      }
    }
  }
  // Function to merge k sorted arrays.
  vector<int> mergeKArrays(vector<vector<int>> arr, int K)
  {
    // code here
    vector<int> res;
    int n = K, k = K;
    solve(arr, res, n, k);
    return res;
  }
};