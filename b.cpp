#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int o = 0; o < q; o++)
  {
    int t = 0;
    cin >> t;

    if (t == 1)
      cout << 6 << endl;
    else if (t % 2 == 0)
      cout << 6 * t + t / 2 << endl;
    else
      cout << 6 * t + t / 2 + 6 << endl;
  }
}