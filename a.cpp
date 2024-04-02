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
    vector<long long> v;
    long long a = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      // init += a;
      v.push_back(a);
    }

    long long sum = 0;
    // vector<> res;
    // res.push_back(sum);

    long long maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      sum = sum + v[i];

      long long new1 = sum + v[i];
      // sum += 2 * v[i];

      maxi = max(maxi, new1);
    }

    // int ans = *max_element(res.begin(), res.end());

    cout << maxi << endl;
  }
}