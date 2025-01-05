#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find the maximum number of meetings that can
  // be performed in a meeting room.
  int maxMeetings(vector<int> &start, vector<int> &end)
  {
    // Your code hereee
    int n = start.size();
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
      v.push_back({start[i], end[i]});
    }

    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
            if(a.second == b.second)return a.first > b.first;
            return (a.second < b.second); });

    int cnt = 1;
    int lasttime = v[0].second;

    for (int i = 1; i < n; i++)
    {
      int first = v[i].first;
      int second = v[i].second;

      if (first > lasttime)
      {
        cnt++;
        lasttime = second;
      }
    }
    return cnt;
  }
};