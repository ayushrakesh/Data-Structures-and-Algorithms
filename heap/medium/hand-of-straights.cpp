#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    int n = hand.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        p;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      m[hand[i]]++;
    }

    for (auto it : m)
    {
      p.push({it.first, it.second});
    }

    while (!p.empty())
    {
      int t = groupSize;
      int top = p.top().first;
      int f = p.top().second;
      p.pop();
      t = t - 1;

      vector<pair<int, int>> temp;
      temp.push_back({top, f});

      while (t--)
      {
        if (p.top().first != (top + 1))
          return false;
        temp.push_back(p.top());
        top = p.top().first;
        p.pop();
      }
      for (int i = 0; i < temp.size(); i++)
      {
        if (temp[i].second - 1 > 0)
        {
          p.push({temp[i].first, temp[i].second - 1});
        }
      }
    }
    return true;
  }
};