#include <bits/stdc++.h>
using namespace std;
int generateKey(int num1, int num2, int num3)
{
  int res = 0;

  for (int i = 0; i < 4; i++)
  {
    if (!(num1 % 10 == 0 || num2 % 10 == 0 || num3 % 10 == 0))
    {
      int a = min(num1 % 10, num2 % 10);
      a = min(a, num3 % 10);

      if (num1 % 10 > 0)
      {
        res = res + (a)*pow(10, i);
      }
    }
    num1 = num1 / 10;
    num2 = num2 / 10;
    num3 = num3 / 10;
  }
  return res;
}