#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;
  while (q--)
  {
    int n;
    int l, r;

    cin >> n >> l >> r;

    int a = 0;
    vector<int> v;
    int h = 0;
    int mini = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      v.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
      if (v[i] <= r && v[i] >= l)
      {
        // maxi++;

        h++;

        // mini = min(h, mini);
      }
      else
      {
        // mini--;
        h--;

        // maxi = max(maxi, h);
      }
      maxi = max(maxi, h);
      mini = min(h, mini);
    }
    cout << maxi << " " << mini << endl;
  }
}