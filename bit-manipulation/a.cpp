#include <bits/stdc++.h>
using namespace std;
void print_divisors(int n)
{
  // Code here.
  vector<int> res, temp;

  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      res.push_back(i);
      // cout<<i<<" ";
    }
  }
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  for (int i = res.size() - 1; i >= 0; i--)
  {
    if (res[i] != sqrt(n))
    {
      cout << (n / res[i]) << " ";
    }
  }
}
int main()
{
  print_divisors(100);
}