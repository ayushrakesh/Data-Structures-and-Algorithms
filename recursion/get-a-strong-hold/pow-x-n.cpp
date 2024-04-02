#include <bits/stdc++.h>
using namespace std;
float powXn(float x, int n)
{
  int cnt = 0;
  double ans = 1;
  long long m;

  if (n < 0)
  {
    if (n == INT_MIN)
    {
      m = abs(n + 1);
    }
    m = abs(n);
  }

  while (cnt < n || cnt < m)
  {
    ans = ans * x;
    cnt++;
  }

  if (n < 0)
  {
    if (n == INT_MIN)
    {
      return 0.5 * (1.00 / ans);
    }
    return (1.00 / ans);
  }
  return ans;
}

double powXOpt(float x, int n)
{
  long long nn = n;
  long double ans = 1;

  if (nn < 0)
  {
    nn = abs(nn);
  }

  while (nn > 0)
  {
    if (nn % 2 == 0)
    {
      x = x * x;
      nn = nn / 2;
    }
    else
    {
      ans = ans * x;
      nn--;
    }
    /* code */
  }

  if (n < 0)
  {
    ans = 1.00 / ans;
  }
  return ans;
}
float powXnRecursive(float x, int n)
{
  long long m;
  if (n < 0)
  {
    m = abs(n);
  }
  if (n == 0 || m == 0)
    return 1;
  if (n == 1 || m == 1)
    return x;

  float rec;

  if (n < 0)
  {
    rec = powXnRecursive(x, m - 1);
    return 1.00 / (rec * x);
  }
  else
  {
    rec = powXnRecursive(x, n - 1);
    return rec * x;
  }
}
int main()
{
  float x;
  int n;

  cin >> x >> n;

  cout << powXOpt(x, n) << endl;
}