#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> &nums, int k)
{
  int cnt = 0;
  int n = nums.size();

  for (int i = 0; i < n; i++)
  {
    int temp = 0;
    for (int j = i; j < n; j++)
    {
      if ((nums[j] % 2) == 1)
      {
        temp++;
      }
      if (temp == k)
      {
        cnt++;
      }
    }
  }
  return cnt;
}