#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;

    if (a % 2 == 1 && b % 2 == 1)
    {
      cout << "NO" << endl;
      continue;
    }
    if (a % 2 == 0 && b % 2 == 1)
    {
      int c = a / 2;
      int d = b;

      int a2 = 2 * c;

      if (a + b != d + a2)
      {
        cout << "YES" << endl;
        continue;
      }

      int b2 = 2 * d;

      if (a + b != b2 + c)
      {
        cout << "YES" << endl;
        continue;
      }

      cout << "NO" << endl;
      continue;
    }

    else if (b % 2 == 0 && a % 2 == 1)
    {

      int c = b / 2;
      int d = a;

      int a2 = 2 * c;

      if (a + b != a2 + d)
      {
        cout << "YES" << endl;
        continue;
      }

      int b2 = 2 * d;

      if (a + b != b2 + c)
      {
        cout << "YES" << endl;
        continue;
      }
      cout << "NO" << endl;
      continue;
    }

    else
    {
      int f = a / 2;
      int g = b / 2;

      int f2 = 2 * f;

      if (a + b != f2 + g)
      {
        cout << "YES" << endl;
        continue;
      }

      int g2 = 2 * g;

      if (a + b != g2 + f)
      {
        cout << "YES" << endl;
        continue;
      }

      cout << "NO" << endl;
      continue;
    }

    // cout << "YES" << endl;
  }
}
