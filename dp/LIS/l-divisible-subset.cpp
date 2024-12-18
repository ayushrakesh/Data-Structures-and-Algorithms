#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
  {
    // Code here
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);
    vector<int> m(n, -1);
    for (int i = 0; i < n; i++)
      m[i] = i;

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if ((arr[i] % arr[j] == 0) && ((dp[j] + 1) > dp[i]))
        {
          dp[i] = 1 + dp[j];
          m[i] = j;
        }
      }
    }
    vector<int> res;
    auto it = max_element(dp.begin(), dp.end());
    int ind = distance(dp.begin(), it);

    while (m[ind] != ind)
    {
      res.push_back(arr[ind]);
      ind = m[ind];
    }
    res.push_back(arr[ind]);
    reverse(res.begin(), res.end());
    return res;
  }
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    return longestIncreasingSubsequence(nums.size(), nums);
  }
};