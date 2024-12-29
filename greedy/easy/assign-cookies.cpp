#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    int n = g.size();
    int m = s.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int cnt = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
      if (s[j] >= g[i])
      {
        cnt++;
        i++;
        j++;
      }
      else
      {
        j++;
      }
    }
    return cnt;
  }
};