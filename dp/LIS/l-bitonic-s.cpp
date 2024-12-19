#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestBitppnicSubsequence(int n, vector<int> &arr)
  {
    // Code here
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (arr[j] < arr[i] && ((dp1[j] + 1) > dp1[i]))
        {
          dp1[i] = 1 + dp1[j];
        }
      }
    }
    auto it = max_element(dp1.begin(), dp1.end());
    int ind = distance(dp1.begin(), it);

    for (int i = n - 2; i >= 0; i--)
    {
      for (int j = n - 1; j > i; j--)
      {
        if (arr[j] < arr[i] && ((dp2[j] + 1) > dp2[i]))
        {
          dp2[i] = 1 + dp2[j];
        }
      }
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
      if (dp1[i] >= 2 && dp2[i] >= 2)
      {
        res = max(res, dp1[i] + dp2[i] - 1);
      }
    }
    return res;
  }
  int LongestBitonicSequence(int n, vector<int> &nums)
  {
    // code here
    if (n == 1 || n == 2)
      return 0;
    return longestBitppnicSubsequence(n, nums);
  }
};