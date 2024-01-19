#include <bits/stdc++.h>
using namespace std;
int linearSearch(vector<int> &v, int d)
{

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == d)
    {
      return i;
      break;
    }
  }
  return -1;
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
  int d;
  cin >> d;
  cout << linearSearch(v, d) << endl;
}