#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isAllStars(string &S1, int i)
  {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++)
    {
      if (S1[j - 1] != '*')
        return false;
    }
    return true;
  }
  int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
  {
    if (j < 0 && i < 0)
      return true;
    if (j < 0 && i >= 0)
      return false;
    if (i < 0 && j >= 0)
    {
      for (int k = 0; k <= j; k++)
      {
        if (t[k] != '*')
          return false;
      }
      return true;
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s[i] == t[j] || t[j] == '?')
      return dp[i][j] = solve(i - 1, j - 1, s, t, dp);
    if (t[j] == '*')
      return dp[i][j] =
                 solve(i, j - 1, s, t, dp) || solve(i - 1, j, s, t, dp);
    return dp[i][j] = false;
  }
  int tab(string s, string t, vector<vector<int>> &dp)
  {
    int n = s.size();
    int m = t.size();

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
      dp[i][0] = false;
    }
    bool b = false;

    for (int i = 1; i <= m; i++)
    {
      dp[0][i] = isAllStars(t, i);
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (s[i - 1] == t[j - 1] || t[j - 1] == '?')
          dp[i][j] = dp[i - 1][j - 1];
        else if (t[j - 1] == '*')
          dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        else
          dp[i][j] = false;
      }
    }

    return dp[n][m];
  }
  bool isMatch(string s, string p)
  {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return tab(s, p, dp);
  }
};