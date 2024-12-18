#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool fun(string a, string b)
  {
    int n = a.size();
    int m = b.size();
    if (m + 1 != n)
      return false;
    int i = 0, j = 0;

    while (i < n)
    {
      if (j < m && a[i] == b[j])
      {
        i++;
        j++;
      }
      else
      {
        i++;
      }
    }
    if (i == n && j == m)
      return true;
    return false;
  }
  static bool comp(const string &s, const string &t)
  {
    return s.size() < t.size();
  }
  int longestIncreasingSubsequence(int n, vector<string> &arr)
  {
    // Code here
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (fun(arr[i], arr[j]) && ((dp[j] + 1) > dp[i]))
        {
          dp[i] = 1 + dp[j];
        }
      }
    }
    auto it = max_element(dp.begin(), dp.end());
    int ind = distance(dp.begin(), it);
    return dp[ind];
  }
  int longestStrChain(vector<string> &words)
  {
    return longestIncreasingSubsequence(words.size(), words);
  }
};