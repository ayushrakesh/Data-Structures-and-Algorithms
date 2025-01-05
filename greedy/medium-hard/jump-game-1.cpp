#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
      if (ind >= i && (nums[i] + i > ind))
      {
        ind = nums[i] + i;
      }

      if (ind >= (n - 1))
        return true;
    }
    return false;
  }
};