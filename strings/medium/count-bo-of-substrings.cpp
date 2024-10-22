#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long int substrCount(string s, int k)
  {
    // code here.

    int n = s.size();
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    long long res = 0;
    while (j < n)
    {

      mp[s[j]]++;

      if (mp.size() == k)
      {
        res++;
      }

      while (mp.size() > k && i <= j)
      {
        mp[s[i]]--;
        if (mp[s[i]] == 0)
        {
          mp.erase(s[i]);
        }
        i++;

        if (mp.size() == k)
        {
          res++;
        }
      }
      j++;
    }

    mp[s[i]]--;
    if (mp[s[i]] == 0)
      mp.erase(s[i]);
    i++;

    while (i < n)
    {
      if (mp.size() == k)
      {
        res++;
      }
      mp[s[i]]--;
      if (mp[s[i]] == 0)
      {
        mp.erase(s[i]);
      }
      i++;
    }
    return res;
  }
};