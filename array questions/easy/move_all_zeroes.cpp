#include <bits/stdc++.h>
using namespace std;
void moveAllZeroes(vector<int> &v)
{
  int j = -1;

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == 0)
    {
      j = i;
      break;
    }
  }

  for (int i = j + 1; i < v.size(); i++)
  {
    if (v[i] != 0)
    {
      swap(v[j], v[i]);
      j++;
    }
  }
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
  moveAllZeroes(v);
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
}