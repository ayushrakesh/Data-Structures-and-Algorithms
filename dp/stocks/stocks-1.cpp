#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<int> aux(n);
    int res = 0;
    int mini = prices[0];
    for (int i = 1; i < n; i++)
    {
      res = max(res, prices[i] - mini);
      mini = min(mini, prices[i]);
    }
    return res;
  }
};