#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int o = 0; o < q; o++)
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
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
      sum += v[i] - v[i - 1];
    }
    cout << sum << endl;
  }
}