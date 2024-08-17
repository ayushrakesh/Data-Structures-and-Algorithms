#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;
  while (q--)
  {
    int n;
    cin >> n;
    vector<int> v;
    int a = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      v.push_back(a);
    }

    sort(v.begin(), v.end());
    bool f = false;
    for (int i = 0; i < n; i++)
    {
      if ((i + 1) - v[i] < 0)
      {
        cout << "NO" << endl;
        f = true;
        break;
      }
    }
    if (!f)
    {
      cout << "YES" << endl;
    }
  }
}