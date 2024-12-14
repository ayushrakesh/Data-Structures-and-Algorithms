#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void tab(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
  {
    // dp[0][0] = (s[0]==t[0]);

    for (int i = 0; i <= ind1; i++)
      dp[i][0] = 0;
    for (int i = 0; i <= ind2; i++)
      dp[0][i] = 0;

    for (int i = 1; i <= ind1; i++)
    {
      for (int j = 1; j <= ind2; j++)
      {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = 0;
      }
    }
  }
  int longestCommonSubsequence(string text1, string text2)
  {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    tab(n, m, text1, text2, dp);

    int res = INT_MIN;

    for (int i = 0; i < dp.size(); i++)
    {
      for (int j = 0; j < dp[0].size(); j++)
      {
        res = max(res, dp[i][j]);
      }
    }
    return res;
  }
  int longestCommonSubstr(string &s1, string &s2)
  {
    // your code here
    return longestCommonSubsequence(s1, s2);
  }
};