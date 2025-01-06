#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to get the maximum total value in the knapsack.
  double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
  {
    // Your code here
    double res = 0;
    int n = val.size();

    vector<pair<double, pair<int, int>>> v;

    for (int i = 0; i < n; i++)
    {
      double d = ((double)val[i] / (double)wt[i]);
      v.push_back({d, {val[i], wt[i]}});
    }

    sort(v.begin(), v.end(), [](pair<double, pair<int, int>> &a, pair<double, pair<int, int>> &b)
         { return a.first > b.first; });

    // for(int i=0;i<n;i++){
    //     cout<<v[i].first <<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
    // }

    int t = 0;

    for (int i = 0; i < n; i++)
    {
      double unit = v[i].first;
      int w = v[i].second.second;
      int va = v[i].second.first;

      if ((w + t) <= capacity)
      {
        t = t + w;
        res = res + va;
      }
      else
      {
        int d = capacity - t;
        res = res + (d * unit);
        break;
      }
    }
    return res;
  }
};