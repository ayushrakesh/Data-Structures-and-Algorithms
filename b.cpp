#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  int q = 0;
  cin >> q;

  while (q--)
  {
    int n;
    int m;
    cin >> n >> m;

    vector<long long> v, w;
    long long a = 0;
    unordered_map<long long, long long> mp;
    long long ways = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      v.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
      long long rem = v[i] % m;
      mp[rem]++;
    }

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      w.push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
      long long rem = w[i] % m;

      if (mp.find((m - rem) % m) != mp.end())
      {
        ways += mp[(m - rem) % m];
      }
    }

    cout << ways << endl;
  }
}
