#include <bits/stdc++.h>
using namespace std;
int minDifference(int n, vector<int> &arr, int x)
{
  // code here
  int res = INT_MAX;
  bool flag = false;

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if ((arr[i] ^ arr[j]) <= x)
      {
        flag = true;
        int diff = abs(arr[i] - arr[j]);
        res = min(res, diff);
      }
    }
  }
  if (!flag)
  {
    return -1;
  }
  return res;
}
int main()
{
  vector<int> v = {1, 4, 2, 8};

  cout << minDifference(4, v, 2) << endl;

  cout << fixed << setprecision(2) << 5.23500 << endl;
}