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

int method2(int n)
{
  int count = 0;

  for (int i = 1; i <= sqrt(n); i++)
  {
    /* code */
    if (n % i == 0)
    {
      if (i == sqrt(n))
      {
        count++;
        break;
      }
      count = count + 2;
    }
  }
  return count;
}

int main()
{

  int n;
  cin >> n;

  cout << method1(n) << endl;
  cout << method2(n) << endl;
}