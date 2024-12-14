#include <bits/stdc++.h>
using namespace std;

int solve(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
{
  if (ind1 < 0 || ind2 < 0)
    return 0;

  if (dp[ind1][ind2] != -1)
    return dp[ind1][ind2];

  if (s[ind1] == t[ind2])
    return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s, t, dp);
  return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s, t, dp),
                              solve(ind1, ind2 - 1, s, t, dp));
}
int tab(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
{
  dp[0][0] = (s[1] == t[1]);

  for (int i = 1; i <= ind1; i++)
    if (s[i] == t[0])
      dp[i][0] = 1;
    else
      dp[i][0] = dp[i - 1][0];
  for (int i = 1; i <= ind2; i++)
    if (s[0] == t[i])
      dp[0][i] = 1;
    else
      dp[0][i] = dp[0][i - 1];

  for (int i = 1; i <= ind1; i++)
  {
    for (int j = 1; j <= ind2; j++)
    {
      if (s[i] == t[j])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[ind1][ind2];
}
string longestCommonSubsequence(string text1, string text2)
{
  int n = text1.size();
  int m = text2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  tab(n, m, text1, text2, dp);

  cout << dp[n - 1][m - 1] << endl;
  int len = dp[n - 1][m - 1];
  int index = len - 1;
  string res = "";
  for (int i = 0; i < len; i++)
  {
    res.push_back('@');
  }

  int i = n - 1, j = m - 1;

  while (i >= 0 && j >= 0)
  {
    if (text1[i] == text2[j])
    {
      res[index] = text1[i];
      index--;
      i--;
      j--;
    }
    else
    {
      if (dp[i - 1][j] > dp[i][j - 1])
        i--;
      else
        j--;
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

string lcs(string s1, string s2)
{

  int n = s1.size();
  int m = s2.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++)
  {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++)
  {
    for (int ind2 = 1; ind2 <= m; ind2++)
    {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  int i = n;
  int j = m;

  string str = "";

  while (i > 0 && j > 0)
  {
    if (s1[i - 1] == s2[j - 1])
    {
      str.push_back(s1[i - 1]);
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      i--;
    }
    else
      j--;
  }
  // cout << str;
  reverse(str.begin(), str.end());
  return str;
}
int main()
{
  string s = "abacab";
  string t = "cab";
  string res = lcs(s, t);
  cout << res << endl;
}