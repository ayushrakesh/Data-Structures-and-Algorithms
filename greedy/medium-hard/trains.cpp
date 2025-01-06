#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find the minimum number of platforms required at the
  // railway station such that no train waits.
  int findPlatform(vector<int> &arr, vector<int> &dep)
  {
    // Your code here
    int n = arr.size();
    int cnt = 1;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
      v.push_back({arr[i], dep[i]});
    }
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.first < b.first; });

    int mini = v[0].second;
    priority_queue<int, vector<int>, greater<int>> p;
    p.push(mini);

    for (int i = 1; i < n; i++)
    {
      if (v[i].first <= mini)
      {
        cnt++;
        p.push(v[i].second);
        mini = p.top();
      }
      else
      {
        p.pop();
        p.push(v[i].second);
        mini = p.top();
      }
    }
    return cnt;
  }
};