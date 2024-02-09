#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> v;
  int n;
  cin >> n;
  int a = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin() + 1, v.begin() + 3);

  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }

  // cout << v.at(0) << endl;
}
