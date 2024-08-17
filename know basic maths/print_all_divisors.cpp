#include <bits/stdc++.h>
using namespace std;

int method1(int n)
{
  int count = 0;

  for (int i = 1; i <= n; i++)
  {
    /* code */
    if (n % i == 0)
    {
      count++;
    }
  }
  return count;
}

int method2(int num)
{
  // int count = 0;

  // for (int i = 1; i <= sqrt(n); i++)
  // {
  //   /* code */
  //   if (n % i == 0)
  //   {
  //     if (i == sqrt(n))
  //     {
  //       count++;
  //       break;
  //     }
  //     count = count + 2;
  //   }
  // }
  // return count;

  int n = sqrt(num);
  int sum = 0;
  int count = 0;
  for (int i = 1; i <= n; i++)
  {
    if (num % i == 0)
    {
      sum += i;
      sum += (num / i);
      count = count + 2;
    }
  }
  count--;
  sum = sum - n;
  sum = sum - num;

  // if (sum == num)
  // {
  //   return true;
  // }
  // else
  // {
  //   return false;
  // }

  return count;
}

int main()
{

  int n;
  cin >> n;

  // cout << method1(n) << endl;
  cout << method2(n) << endl;

  // method2(n);
}