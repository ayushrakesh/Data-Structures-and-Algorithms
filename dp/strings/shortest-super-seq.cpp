#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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

    string res = "";

    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0)
    {
      if (text1[i] == text2[j])
      {
        res.push_back(text1[i]);
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
          dp[ind1][ind2] =
              0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
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
  string shortestCommonSupersequence(string str1, string str2)
  {
    string s = lcs(str1, str2);
    string res = "";
    int i = 0, j = 0, k = 0;

    while (i < s.size())
    {
      char c = s[i];
      while (j < str1.size() && str1[j] != c)
      {
        res.push_back(str1[j]);
        j++;
      }
      while (k < str2.size() && str2[k] != c)
      {
        res.push_back(str2[k]);
        k++;
      }
      res.push_back(c);
      i++;
      j++;
      k++;
    }
    while (j < str1.size())
    {
      res.push_back(str1[j]);
      j++;
    }
    while (k < str2.size())
    {
      res.push_back(str2[k]);
      k++;
    }
    return res;
  }
};