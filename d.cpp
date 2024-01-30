#include <bits/stdc++.h>
using namespace std;
int main()
{
  int q = 0;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int n, m;
    cin >> n >> m;
    int sum = 0, count = 0;
    vector<int> v;

    for (int j = 0; j < n; j++)
    {
      int a;
      cin >> a;
      v.push_back(a);
    }

    // cout << v.at(0) << endl;

    for (int j = 0; j < n; j++)
    {
      if (v[j] + sum < m)
      {
        sum += v[j];
        continue;
      }
      count++;
      sum = 0;
    }
    cout << count << endl;
  }
}