#include <bits/stdc++.h>
using namespace std;
int main()
{
  int q = 0;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int n, k;
    cin >> n >> k;
    int sum = 0, count = 0;
    vector<int> v;

    for (int j = 0; j < n; j++)
    {

      v.push_back(j + 1);
    }

    for (int j = 0; j < n; j++)
    {
      vector<int> w;
      for (int k = 1; k <= v[j]; k++)
      {
        if (v[j] % (k) == 0)
        {
          w.push_back(k);
        }
      }
    }
  }
}