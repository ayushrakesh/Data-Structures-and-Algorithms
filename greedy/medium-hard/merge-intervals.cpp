#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    vector<vector<int>> res;
    int i = 0;

    while (i < n)
    {
      int cs = intervals[i][0];
      int ce = intervals[i][1];
      i++;

      while (i < n && intervals[i][0] <= ce)
      {
        cs = min(cs, intervals[i][0]);
        ce = max(ce, intervals[i][1]);
        i++;
      }
      res.push_back({cs, ce});
    }

    return res;
  }
};