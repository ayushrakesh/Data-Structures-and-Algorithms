#include <bits/stdc++.h>
using namespace std;
string convertBinary(int n)
{
  string s = "";

  while (n != 1)
  {
    int rem = n % 2;

    if (rem == 0)
    {
      s = s + "0";
    }
    else
    {
      s = s + "1";
    }
    n = n / 2;
    /* code */
  }
  reverse(s.begin(), s.end());
  // reverseString(s);
  return "1" + s;
}
int checkSetBits(string s)
{
  int cnt = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '1')
      cnt++;
  }
  return cnt;
}
int main()
{
  int n;
  cin >> n;

  if (n == 0)
    cout << "NO" << endl;
  return 0;
  string s = convertBinary(n);

  if (checkSetBits(s) == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}