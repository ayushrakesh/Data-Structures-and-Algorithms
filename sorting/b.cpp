#include <bits/stdc++.h>
using namespace std;
void insertionRecur(vector<int> &v, int ind)
{
  if (ind >= v.size())
  {
    return;
  }

  for (int i = ind; i >= 1; i--)
  {
    if (v[i] < v[i - 1])
    {
      swap(v[i], v[i - 1]);
    }
  }
  insertionRecur(v, ind + 1);
}
int main()
{
  vector<int> v = {1, 1, 5, 4, 0, 8, 7, 5, 2};

  insertionRecur(v, 0);

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}