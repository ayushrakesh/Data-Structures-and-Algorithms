#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    int n = nums.size();
    // priority_queue<int> p(nums.begin(), nums.end());
    // for (int i = 0; i < k - 1; i++)
    //     p.pop();
    // return p.top();

    priority_queue<int, vector<int>, greater<int>> p(nums.begin(), nums.begin() + k);
    for (int i = k; i < n; i++)
    {
      if (nums[i] > p.top())
      {
        p.pop();
        p.push(nums[i]);
      }
    }
    return p.top();
  }
};