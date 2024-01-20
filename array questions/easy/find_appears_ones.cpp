#include <bits/stdc++.h>
using namespace std;
int findAppearsOnes(vector<int> v)
{
  int xr = 0;

  for (int i = 0; i < v.size(); i++)
  {
    xr = xr ^ v[i];
  }
  return xr;
}
int main()
{
  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v.push_back(a);
  }

  cout << findAppearsOnes(v) << endl;
}