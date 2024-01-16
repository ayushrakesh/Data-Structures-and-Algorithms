#include <bits/stdc++.h>
using namespace std;
int main()
{
  int q = 0;
  cin >> q;

  while (q != 0)
  {
    vector<int> v;
    vector<int> w;
    // vector<pair<int, int>> v2;

    int n;
    cin >> n;
    int m;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      v.push_back(a);
    }
    for (int i = 0; i < m; i++)
    {
      int a;
      cin >> a;
      w.push_back(a);
    }

    sort(v.begin(), v.end());
    sort(w.begin(), w.end(), greater<int>());

    int diff = m - n;
    int sum = 0;

    for (int i = 0; i < n - diff; i++)
    {
      sum = sum + abs(v[i] - w[i]);
    }
    for (int i = n - diff; i < n; i++)
    {
      sum = sum + abs(v[i] - w[i + diff]);
    }

    cout << sum << endl;
    q--;
  }
}
