#include <bits/stdc++.h>
using namespace std;

int secondSmallest(vector<int> v, int n)
{
  int smallest = v[0];
  int ssmallest = INT_MAX;

  for (int i = 1; i < n; i++)
  {
    if (v[i] < smallest)
    {
      ssmallest = smallest;
      smallest = v[i];
    }
    else if (v[i] > smallest && v[i] < ssmallest)
    {
      ssmallest = v[i];
    }
  }
  return ssmallest;
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

  cout << secondSmallest(v, n) << endl;
}