#include <bits/stdc++.h>
using namespace std;

void printOnetoN(int i, int n)
{
  if (i > n)
    return;
  cout << i << endl;
  printOnetoN(i + 1, n);
}

int main()
{

  int n;
  cin >> n;

  printOnetoN(1, n);
}