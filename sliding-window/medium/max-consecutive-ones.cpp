#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxlen = 0;
  int left = 0, right = 0;

  int cnt = 0;
  int ind = -1;

  while (right < n)
  {
    if (nums[right] == 0)
    {
      cnt++;
    }
    if (cnt > k)
    {
      if (nums[left] == 0)
      {
        cnt--;
      }
      left++;
    }

    if (cnt <= k)
    {
      maxlen = max(maxlen, right - left + 1);
    }
    right++;
  }

  return maxlen;
}

int brute(vector<int> &nums, int k)
{
  int n = nums.size();
  int maxlen = 0;

  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = i; j < n; j++)
    {
      if (nums[j] == 0)
      {
        if (cnt < k)
        {
          cnt++;
        }
        else
        {
          break;
        }
      }
      maxlen = max(maxlen, j - i + 1);
    }
  }
  return maxlen;
}
