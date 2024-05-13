#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s)
{
  reverse(s.begin(), s.end());
}
string decimalToBinary(int n)
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
  reverseString(s);
  return "1" + s;
}
int main()
{
  int n;
  cin >> n;

  cout << decimalToBinary(n) << endl;
}