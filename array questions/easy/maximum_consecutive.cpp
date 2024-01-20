#include <bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector<int> v)
{
  int maxi = 0;
  int count = 0;

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == 1)
    {
      count++;
    }
    else
    {
      count = 0;
    }
    maxi = max(maxi, count);
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

  cout << maxConsecutiveOnes(v) << endl;
}