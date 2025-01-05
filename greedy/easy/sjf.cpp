#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long solve(vector<int> &bt)
  {
    // code here
    long long s = 0;
    long long t = 0;
    sort(bt.begin(), bt.end());
    for (int i = 1; i < bt.size(); i++)
    {
      s += bt[i - 1];
      t += s;
    }
    return (t / bt.size());
  }
};