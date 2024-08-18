#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums, int k)
{
  int n = nums.size();
  int cnt = 0;
  unordered_map<int, int> mp;
  int left = 0, right = 0;

  while (right < n)
  {
    mp[nums[right]]++;

    while (mp.size() > k)
    {
      mp[nums[left]]--;
      if (mp[nums[left]] == 0)
      {
        mp.erase(nums[left]);
      }
      left++;
    }

    if (mp.size() <= k)
    {
      cnt = cnt + (right - left + 1);
    }
    right++;
  }
  return cnt;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
  return solve(nums, k) - solve(nums, k - 1);
}
int brute(vector<int> &nums, int k)
{
  int n = nums.size();
  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    unordered_map<int, int> mmp;
    for (int j = i; j < n; j++)
    {
      mmp[nums[j]]++;

      if (mmp.size() == k)
      {
        cnt++;
      }
    }
  }
  return cnt;
}
int main()
{
  vector<int> v = {1, 2, 1, 3, 4};
  int k = 0;
  cin >> k;
  cout << subarraysWithKDistinct(v, k) << endl;
}