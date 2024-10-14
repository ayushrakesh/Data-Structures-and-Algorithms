#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumMultiplications(vector<int> &arr, int start, int end)
  {
    // code here
    vector<int> res(100000, INT_MAX);
    queue<pair<int, int>> q;
    q.push({start, 0});
    res[start] = 0;

    while (!q.empty())
    {
      int node = q.front().first;
      int dis = q.front().second;

      q.pop();

      for (auto it : arr)
      {
        int d = (it * node) % 100000;
        if (res[d] > dis + 1)
        {
          res[d] = dis + 1;
          q.push({d, dis + 1});

          if (d == end)
            return dis + 1;
        }
      }
    }
    return -1;
  }
};
