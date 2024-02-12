#include <bits/stdc++.h>
using namespace std;

int func(int mid, int n, int m)
{
  // return 1 if ans==m
  // return 0 if ans<m
  // return 2 if ans >m

  long long ans = 1;

  for (int i = 1; i <= n; i++)
  {
    /* code */
    ans = ans * mid;

    if (ans > m)
      return 2;
  }

  if (ans == m)
    return 1;
  else
    return 0;
}
int nthRoot(int m, int n)
{
  int ans = 1;

  if (m == 0)
    return 0;
  int low = 1, high = m;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (func(mid, n, m) == 1)
      return mid;
    else if (func(mid, n, m) == 0)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
int main()
{
  int m, n;
  cin >> m >> n;

  cout << nthRoot(m, n) << endl;
}