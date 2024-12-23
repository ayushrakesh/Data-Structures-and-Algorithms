#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // arr : given array
  // k : find kth smallest element and return using this function
  int findKthSmallest(vector<int> &nums, int k)
  {
    int n = nums.size();
    priority_queue<int> p(nums.begin(), nums.begin() + k);
    for (int i = k; i < n; i++)
    {
      if (nums[i] < p.top())
      {
        p.pop();
        p.push(nums[i]);
      }
    }
    return p.top();
  }
  int kthSmallest(vector<int> &arr, int k)
  {
    // code here
    return findKthSmallest(arr, k);
  }
};