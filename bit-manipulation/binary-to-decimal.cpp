#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string s)
{

  int n = 0;

  for (int i = s.length() - 1; i >= 0; i--)
  {

    if (s[i] == '1')
    {
      int index = s.length() - i - 1;
      n = n + pow(2, index);
    }
  }
  return n;
}
int main()
{
  string s;
  cin >> s;

  int res = binaryToDecimal(s);

  cout << res << endl;
}