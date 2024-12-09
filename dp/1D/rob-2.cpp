#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int optimal(vector<int> &nums, int ind)
  {
    int n = nums.size();
    int left = nums[n - 1];
    int right = 0;

    for (int i = n - 2; i >= 0; i--)
    {
      int t = left;
      left = max(nums[i] + right, t);
      right = t;
    }
    return left;
  }
  int rob(vector<int> &nums)
  {
    vector<int> u, v;
    int n = nums.size();
    if (n == 1)
      return nums[0];
    for (int i = 0; i < n; i++)
    {
      if (i != 0)
        u.push_back(nums[i]);
      if (i != (n - 1))
        v.push_back(nums[i]);
    }
    return max(optimal(u, 0), optimal(v, 0));
  }
};