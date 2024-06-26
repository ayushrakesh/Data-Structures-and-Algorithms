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
double powXnRecursive(float x, int n)
{
  if (n == 0)
  {
    return 1;
  }

  double f = 0.0;

  if (abs(n) % 2 == 0)
  {
    f = powXnRecursive(x, abs(n) / 2);

    if (n < 0)
    {
      return (1.00 / (f * f));
    }
    return f * f;
  }
  else
  {
    f = powXnRecursive(x, abs(n) - 1);
    // f=f*x;

    if (n < 0)
    {
      return (1.00 / (f * x));
    }
    return f * x;
  }
}
int main()
{
  float x;
  int n;

  cin >> x >> n;

  cout << powXOpt(x, n) << endl;
  cout << powXnRecursive(x, n) << endl;
}