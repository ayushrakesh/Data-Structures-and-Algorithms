#include <bits/stdc++.h>
using namespace std;
long long powXN(int x, int n)
{
  if (n == 0)
  {
    return 1;
  }

  long long l = 0;

  if (n % 2 == 0)
  {
    l = powXN(x, n / 2);
    return l * l;
  }
  else
  {
    l = powXN(x, n - 1);
    return l * x;
  }
}
long long countGoodNumbers(int n)
{
  // double d = n / 2.00;
  int evenDigits = ceil(n / 2.0);
  int oddDigits = floor(n / 2.0);

  cout << evenDigits << " " << oddDigits << endl;
  return powXN(5, evenDigits) * powXN(4, oddDigits);
}
int main()
{
  int n;
  cin >> n;

  cout << countGoodNumbers(n) << endl;
}