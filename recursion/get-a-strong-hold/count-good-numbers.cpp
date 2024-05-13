#include <bits/stdc++.h>
using namespace std;

int countGoodNumbers(int n)
{
  if (n % 2 == 0)
  {
    return pow(5, n / 2) * pow(4, n / 2);
  }
  else
    return pow(5, n / 2 + 1) * pow(4, n / 2);
}
int main()
{
  int n;
  cin >> n;

  cout << countGoodNumbers(n) << endl;
}