#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  while (q--)
  {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    int a = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      v.push_back(a);
    }

    vector<int> w = v;
    int maxi = 0;

    for (int i = 0; i < n - 1; i++)
    {
      maxi = maxi + abs((w[i] - w[i + 1]));
    }

    for (int i = 0; i < n; i++)
    {
      int temp = w[i];

      w[i] = 1;
      int t = 0;

      for (int j = 0; j < n - 1; j++)
      {
        t = t + abs((w[j] - w[j + 1]));
      }

      maxi = max(t, maxi);

      w[i] = k;
      t = 0;

      for (int j = 0; j < n - 1; j++)
      {
        t = t + abs((w[j] - w[j + 1]));
      }

      maxi = max(t, maxi);
      w[i] = temp;
    }
    cout << maxi << endl;
  }
}