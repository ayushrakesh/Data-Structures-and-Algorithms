#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int n;
    cin >> n;
    vector<int> v;
    vector<int> w;
    int a = 0;

    for (int j = 0; j < n; j++)
    {
      cin >> a;
      v.push_back(a);
    }
    w = v;

    if (n == 1)
      cout << "YES" << endl;
    else if (n == 2)
    {
      if (v[0] <= v[1])
        cout << "YES" << endl;
      else
      {
        cout << "NO" << endl;
      }
    }
    else if (n == 3)
    {
      if (v[1] < min(v[0], v[2]) || v[1] > max(v[0], v[2]))
      {
        cout << "NO" << endl;
      }
      else
      {
        cout << "YES" << endl;
      }
    }
    else
      cout << "YES" << endl;
  }
}