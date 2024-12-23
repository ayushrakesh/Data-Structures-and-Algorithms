#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> replaceWithRank(vector<int> &arr, int N)
  {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    for (int i = 0; i < N; i++)
    {
      p.push({arr[i], i});
    }
    int rank = 1;
    vector<int> res(N, -1);
    int pre = -1;
    while (!p.empty())
    {
      int ele = p.top().first;
      int ind = p.top().second;
      p.pop();

      if (pre == -1)
      {
        res[ind] = rank;
        rank++;
        pre = ele;
        continue;
      }
      if (ele == pre)
      {
        res[ind] = rank - 1;
      }
      else
      {
        res[ind] = rank;
        rank++;
        pre = ele;
      }
    }
    return res;
  }
};