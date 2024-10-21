#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string frequencySort(string s)
  {
    unordered_map<char, int> mp;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
      mp[s[i]]++;
    }
    priority_queue<pair<int, char>> pq;

    for (auto it : mp)
    {
      char c = it.first;
      int f = it.second;
      pq.push({f, c});
    }
    string res = "";
    while (!pq.empty())
    {
      int f = pq.top().first;
      char c = pq.top().second;

      pq.pop();

      while (f)
      {
        res.push_back(c);
        f--;
      }
    }
    return res;
  }
};