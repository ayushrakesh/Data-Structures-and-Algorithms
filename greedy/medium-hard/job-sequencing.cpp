#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                            vector<int> &profit)
  {
    // code here
    int count = 0, pro = 0;
    vector<int> res;
    int n = id.size();
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
      v.push_back({profit[i], {deadline[i], id[i]}});
    }

    sort(v.begin(), v.end(), [](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
         { return a.first > b.first; });

    int maxD = *max_element(deadline.begin(), deadline.end());

    vector<int> arr(maxD + 1, -1);

    for (int i = 0; i < n; i++)
    {
      int id = v[i].second.second;
      int d = v[i].second.first;
      int p = v[i].first;

      for (int j = d; j >= 1; j--)
      {
        if (arr[j] == -1)
        {
          arr[j] = id;
          count++;
          pro = pro + p;
          break;
        }
      }
    }
    res.push_back(count);
    res.push_back(pro);
    return res;
  }
};