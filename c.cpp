#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    float p, l;
    cin >> p >> l;

    float per = (l / p) * 100;

    if (per >= 75)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}