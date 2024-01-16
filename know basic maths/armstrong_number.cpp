#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  int temp = n;
  long long sum = 0;
  while (temp != 0)
  {
    int rem = temp % 10;
    sum = sum + (rem * rem * rem);
    temp = temp / 10;
  }
  if (sum == n)
  {

    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}