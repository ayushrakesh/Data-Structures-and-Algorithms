#include <bits/stdc++.h>
using namespace std;

void rotateLeftD(vector<int> &v, int d)
{
  d = d % v.size();

  reverse(v.begin(), v.begin() + d);
  reverse(v.begin() + d, v.end());
  reverse(v.begin(), v.end());
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

  rotateLeftD(v, d);

  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
}