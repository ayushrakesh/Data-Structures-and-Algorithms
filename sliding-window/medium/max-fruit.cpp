#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> &nums)
{
  int maxfruit = 0;
  int n = nums.size();

  for (int i = 0; i < n; i++)
  {
    unordered_map<int, int> mp;
    for (int j = i; j < n; j++)
    {
      mp[nums[j]]++;

      if (mp.size() >= 3)
      {
        break;
      }
      maxfruit = max(maxfruit, j - i + 1);
    }
  }
  return maxfruit;
}

int totalFruits(vector<int> &arr)
{
  int n = arr.size();

  int left = 0, right = 0;
  unordered_map<int, int> mmp;
  int maxlen = 0;

  while (right < n)
  {
    mmp[arr[right]]++;

    if (mmp.size() > 2)
    {
      mmp[arr[left]]--;
      if (mmp[arr[left]] == 0)
      {
        mmp.erase(arr[left]);
      }
      left++;
    }
    if (mmp.size() <= 2)
    {
      maxlen = max(maxlen, right - left + 1);
    }
    right++;
  }
  return maxlen;
}