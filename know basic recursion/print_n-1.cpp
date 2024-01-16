#include <bits/stdc++.h>
using namespace std;

void printNtoOne(int i, int n)
{
  if (n < i)
    return;
  cout << n << endl;
  printNtoOne(i, n - 1);
}

int main()
{
  int n;
  cin >> n;

  printNtoOne(1, n);
}