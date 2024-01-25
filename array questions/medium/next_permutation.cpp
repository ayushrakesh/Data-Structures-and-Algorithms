#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> v)
{
  int index = -1;

  for (int i = v.size() - 2; i >= 0; i--)
  {
    /* code */
    if (v[i] < v[i + 1])
    {
      index = i;
      break;
    }
  }

  if (index == -1)
  {
    reverse(v.begin(), v.end());
    return v;
  }

  for (int i = v.size() - 1; i > index; i--)
  {
    /* code */

    if (v[i] > v[index])
    {
      swap(v[i], v[index]);
      break;
    }
  }

  reverse(v.begin() + index + 1, v.end());
  return v;
}
int main()
{
  int n;
  cin >> n;
  int a;

  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  vector<int> res = nextPermutation(v);

  for (int i = 0; i < n; i++)
  {
    cout << res[i] << " ";
  }
}