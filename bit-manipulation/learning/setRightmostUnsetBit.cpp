#include <bits/stdc++.h>
using namespace std;
int setRightMostUnsetBit(int n)
{
  string s = "";
  while (n != 1)
  {
    int rem = n % 2;
    if (rem == 0)
    {
      s.append("0");
    }
    else
    {
      s.append("1");
    }
  }
  reverse(s.begin(), s.end());
  s = "1" + s;
}
int main()
{
  int n;
  cin >> n;

  cout << setRightMostUnsetBit(n) << endl;
}