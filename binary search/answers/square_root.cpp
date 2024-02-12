#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n)
{
  int ans = 1;
  int low = 1, high = n;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (mid * mid <= n)
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return ans;
}
int main()
{
  int n;
  cin >> n;

  cout << squareRoot(n) << endl;
}