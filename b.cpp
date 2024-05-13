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

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      /* code */
      cnt = cnt + abs(v[i] - i);
    }
    cout << cnt << endl;
  }
}