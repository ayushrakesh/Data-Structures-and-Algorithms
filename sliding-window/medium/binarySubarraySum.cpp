#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> &nums, int goal)
{
  int cnt = 0;
  int n = nums.size();

  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];

      if (sum > goal)
      {
        break;
      }
      else if (sum == goal)
      {
        cnt++;
      }
    }
  }
  return cnt;
}
// gives the no. of subarrays where sum<=goal
int fun(vector<int> &nums, int goal)
{
  if (goal < 0)
    return 0;
  int cnt = 0;
  int left = 0, right = 0;
  int n = nums.size();
  int sum = 0;

  while (right < n)
  {
    sum += nums[right];

    while (sum > goal)
    {
      sum -= nums[left];
      left++;
    }
    cnt = cnt + (right - left + 1);
    right++;
  }
  return cnt;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
  // gives the no. of subarrays equal to goal
  return fun(nums, goal) - fun(nums, goal - 1);
}

int main()
{
}