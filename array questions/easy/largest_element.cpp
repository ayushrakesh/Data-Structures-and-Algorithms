#include <bits/stdc++.h>
using namespace std;
int largest(vector<int> v, int n)
{
  int maxi = v[0];

  for (int i = 0; i < n; i++)
  {
    if (v[i] > maxi)
      maxi = v[i];
  }
  return maxi;
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

  cout << largest(v, n) << endl;
}