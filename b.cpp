#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int o = 0; o < q; o++)
  {
    int n, k;
    cin >> n >> k;

    // int t = 2 * n;
    int count = 0;
    int sum = 0;

    if (k <= 2 * (2 * n - 2))
    {
      count = (k + 1) / 2;
    }
    else if (k == (2 * (2 * n - 2)) + 1)
    {
      count = ((k + 1) / 2) + 1;
    }
    else
    {
      count = ((k + 1) / 2) + 2;
    }
    cout << count << endl;
  }
}