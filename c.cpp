#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int o = 0; o < q; o++)
  {
    long long k, x, a;
    cin >> k >> x >> a;

    long long v = 0;
    bool g = false;

    for (int i = 0; g && i < x; i++)
    {
      /* code */ long long b = (v - 1 + k) / (k - 1);

      if (b == 0)
        v++;
      else
      {
        v = v + b;
      }

      if (v <= a)
        g = true;
      else
        g = false;
    }

    if (k * (a - v) > a)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}