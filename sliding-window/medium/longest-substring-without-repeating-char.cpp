#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
  int n = s.size();
  if (n == 0)
    return 0;
  int left = 0, right = 0;
  int maxLen = INT_MIN;
  vector<int> arr(256, -1);

  while (right < n)
  {
    if (arr[s[right]] != -1)
    {

      left = max(left, arr[s[right]] + 1);
    }
    maxLen = max(maxLen, right - left + 1);
    arr[s[right]] = right;
    right++;
  }
  return maxLen;
}

int brute(string s)
{
  int n = s.size();
  int maxlen = 0;

  for (int i = 0; i < n; i++)
  {
    unordered_map<char, int> mp;
    for (int j = i; j < n; j++)
    {
      mp[s[j]]++;

      if (mp.size() >= (j - i + 1))
      {
        maxlen = max(maxlen, j - i + 1);
      }
      else
      {
        break;
      }
    }
  }
  return maxlen;
}

int main()
{
  string s;
  cin >> s;

  cout << brute(s) << endl;
}