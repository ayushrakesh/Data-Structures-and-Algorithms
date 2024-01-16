#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;

  int temp = n;
  long long reverse = 0;

  while (temp != 0)
  {
    long long ld = temp % 10;
    temp = temp / 10;

    reverse = reverse * 10 + ld;
  }
  if (reverse == n)
  {

    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}