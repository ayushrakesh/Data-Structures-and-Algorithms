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
    set<int, greater<int>> s;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      v.push_back(a);
      s.insert(a);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    v.erase(remove(v.begin(), v.end(), 5), v.end());
    // v.erase(v.begin() + 0, v.begin() + 2);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
      // sum += v[i];
      // i = i + 2;
      cout << v[i] << " ";
    }
    cout << endl;
    cout << sum << endl;

    for (auto it : s)
    {
      cout << it << " ";
    }
  }
}