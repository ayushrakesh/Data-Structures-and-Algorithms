#include <bits/stdc++.h>
using namespace std;

bool fun(int l, int r, string t)
{
  if (l >= r)
  {
    return true;
  }
  if (t[l] != t[r])
  {
    return false;
  }
  return fun(l + 1, r - 1, t);
}
bool isPalindrome(string s)
{

  string t = "";

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] <= 90 && s[i] >= 65)
    {
      t.push_back(s[i] + 32);
    }
    else if (s[i] <= 122 && s[i] >= 97)
    {
      t.push_back(s[i]);
    }
    else if (s[i] <= 57 && s[i] >= 48)
    {
      t.push_back(s[i]);
    }
  }
  // cout << t << endl;

  return fun(0, t.size() - 1, t);
}

int main()
{
  string s;
  cin >> s;

  cout << isPalindrome(s) << endl;
}