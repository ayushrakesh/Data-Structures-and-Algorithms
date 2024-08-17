#include <bits/stdc++.h>
using namespace std;
void bubbleRecur(vector<int> &v, int ind)
{
  if (ind <= 0)
  {
    return;
  }

  for (int i = 0; i < ind; i++)
  {
    if (v[i] > v[i + 1])
    {
      swap(v[i], v[i + 1]);
    }
  }
  bubbleRecur(v, ind - 1);
}
int main()
{
  vector<int> v = {1, 1, 5, 4, 0, 8, 7, 5, 2};

  bubbleRecur(v, v.size() - 1);

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}