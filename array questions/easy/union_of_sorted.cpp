#include <bits/stdc++.h>
using namespace std;

vector<int> unionOfSorted(vector<int> &v, vector<int> &w)
{
  vector<int> z;
  int i = 0, j = 0;

  for (; i < v.size() && j < w.size();)
  {
    if (v[i] <= w[j])
    {
      if (z[z.size() - 1] != v[i] || z.size() == 0)
      {
        z.push_back(v[i]);
      }
      i++;
    }

    else
    {
      if (z[z.size() - 1] != w[j] || z.size() == 0)
      {
        z.push_back(w[j]);
      }
      j++;
    }
  }

  while (i < v.size())
  {
    if (v[i] != z.back() || z.size() == 0)
    {
      z.push_back(v[i]);
    }
    i++;
  }
  while (j < w.size())
  {
    if (w[j] != z.back() || z.size() == 0)
    {
      z.push_back(w[j]);
    }
    j++;
  }

  return z;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> v;
  vector<int> w;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v.push_back(a);
  }
  for (int i = 0; i < m; i++)
  {
    int a;
    cin >> a;
    w.push_back(a);
  }

  vector<int> z = unionOfSorted(v, w);

  for (int i = 0; i < z.size(); i++)
  {
    cout << z[i] << " ";
  }
}