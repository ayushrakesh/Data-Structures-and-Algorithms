#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval)
  {
    int n = intervals.size();
    vector<vector<int>> res;

    int i = 0;

    while (i < n && (newInterval[0] > intervals[i][1]))
    {
      res.push_back(intervals[i]);
      i++;
    }
    int cs = newInterval[0];
    int ce = newInterval[1];

    if (i <= (n - 1))
    {
      if (newInterval[1] < intervals[i][0])
      {
        res.push_back(newInterval);
        while (i < n)
        {
          res.push_back(intervals[i]);
          i++;
        }
        return res;
      }
      cs = min(intervals[i][0], newInterval[0]);
      ce = max(intervals[i][1], newInterval[1]);
    }
    i++;

    while (i < n && (ce >= intervals[i][0]))
    {
      cs = min(cs, intervals[i][0]);
      ce = max(ce, intervals[i][1]);
      i++;
    }

    res.push_back({cs, ce});

    while (i < n)
    {
      res.push_back(intervals[i]);
      i++;
    }
    return res;
  }
};