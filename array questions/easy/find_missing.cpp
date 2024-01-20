#include <bits/stdc++.h>
using namespace std;
int findMissing(vector<int> v)
{
  int maxi = *max_element(v.begin(), v.end());

  int sum = ((maxi * (maxi + 1)) / 2);

  int sum2 = 0;

  for (int i = 0; i < v.size(); i++)
  {
    sum2 += v[i];
  }
  return sum - sum2;
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

  cout << findMissing(v) << endl;
}