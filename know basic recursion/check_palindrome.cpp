#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(int i, int n, string s)
{
  if (i >= n / 2)
    return true;
  if (s[i] != s[n - i - 1])
    return false;

  return checkPalindrome(i + 1, n, s);
}

int main()
{
  string s;
  cin >> s;

  cout << checkPalindrome(0, s.length(), s) << endl;
}