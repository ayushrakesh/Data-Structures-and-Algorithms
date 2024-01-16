#include <bits/stdc++.h>
using namespace std;

void printOnetoNBacktracking(int i, int n)
{
  if (i < 1)
    return;
  printOnetoNBacktracking(i - 1, n);
  cout << i << endl;
}
int main()
{
  int n;
  cin >> n;

  printOnetoNBacktracking(n, n);
}