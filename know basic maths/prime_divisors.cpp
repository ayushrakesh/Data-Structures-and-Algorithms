#include <bits/stdc++.h>
using namespace std;

bool method2(int n)
{
  int count = 0;

  for (int i = 1; i <= sqrt(n); i++)
  {
    /* code */
    if (n % i == 0)
    {
      if (i == sqrt(n))
      {
        count++;
        break;
      }
      count = count + 2;
    }
  }

  if (count == 2)
  {
    return true;
  }
  return false;
}

int main()
{
  int n;
  cin >> n;

  cout << method2(n);
}