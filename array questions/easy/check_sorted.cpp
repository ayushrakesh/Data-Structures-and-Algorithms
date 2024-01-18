#include <bits/stdc++.h>
using namespace std;
bool isSorted(vector<int> v, int n)
{
  for (int i = 1; i < n; i++)
  {
    if (v[i] >= v[i - 1])
    {
    }
    else
    {
      return false;
    }
  }
  return true;
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

  cout << isSorted(v, n) << endl;
}