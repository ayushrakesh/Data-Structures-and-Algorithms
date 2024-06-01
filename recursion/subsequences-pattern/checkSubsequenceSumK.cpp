#include <bits/stdc++.h>
using namespace std;

bool solve(int ind, vector<int> a, vector<int> &v, int k, int n, int &temp)
{

  if (ind == n)
  {
    if (temp == k)
    {
      return true;
    }
    else
      return false;
  }

  v.push_back(a[ind]);
  temp += a[ind];

  if (solve(ind + 1, a, v, k, n, temp) == true)
  {
    return true;
  }

  v.pop_back();
  temp -= a[ind];

  if (solve(ind + 1, a, v, k, n, temp) == true)
  {
    return true;
  }

  return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
  // Write your code here
  vector<int> v;
  int temp = 0;
  return solve(0, a, v, k, n, temp);
}

int main()
{
  vector<int> a;
  int n, k;
  cin >> n >> k;
  int l = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> l;
    a.push_back(l);
  }

  cout << isSubsetPresent(n, k, a);
}