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
    vector<pair<int, int>> r;

    for (int i = 0; i < n; i++)
    {
      pair<int, int> p;

      cin >> p.first >> p.second;

      r.push_back(p);
    }
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i != j)
        {
          int t = r[i].first * r[j].second + r[i].second * r[j].first;
          maxi = max(maxi, t);
        }
      }
    }
    cout << maxi << endl;
  }
}