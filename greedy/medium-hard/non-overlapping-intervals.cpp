#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    int n = intervals.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
      v.push_back({intervals[i][0], intervals[i][1]});
    }

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });

    int cnt = 1;
    int last = v[0].second;

    for (int i = 1; i < n; i++)
    {
      int start = v[i].first;
      int end = v[i].second;

      if (start >= last)
      {
        cnt++;
        last = end;
      }
    }
    return n - cnt;
  }
};