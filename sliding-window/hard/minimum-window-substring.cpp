#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t)
{
  int n = s.size();
  int m = t.size();
  int startind = -1;
  int minlen = INT_MAX;
  int left = 0, right = 0;
  unordered_map<char, int> mp;
  int cnt = 0;

  for (int i = 0; i < m; i++)
  {
    mp[t[i]]++;
  }

  while (right < n)
  {
    if (mp[s[right]] > 0)
    {
      cnt++;
    }
    mp[s[right]]--;

    while (cnt == m)
    {
      startind = left;
      minlen = min(minlen, right - left + 1);

      mp[s[left]]++;
      if (mp[s[left]] > 0)
      {
        cnt--;
      }
      left++;
    }
    right++;
  }
  if (startind == -1)
  {
    return "";
  }
  return s.substr(startind, minlen);
}

string brute(string s, string t)
{
  unordered_map<char, int> mpt;
  // int ind = -1;
  string ans = "";
  int n = t.size();
  int m = s.size();
  int minlen = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    mpt[t[i]]++;
  }

  for (int i = 0; i < m; i++)
  {
    int cnt = 0;
    unordered_map<char, int> mps = mpt;

    for (int j = i; j < m; j++)
    {
      if (mps[s[j]] > 0)
      {
        mps[s[j]]--;
        cnt++;
      }
      if (cnt == n)
      {
        if (j - i + 1 < minlen)
        {
          minlen = j - i + 1;
          ans = s.substr(i, j - i + 1);
        }
        break;
      }
    }
  }
  return ans;
}
int main()
{
  string s, t;
  cin >> s >> t;

  cout << minWindow(s, t) << endl;
}
