#include <bits/stdc++.h>
using namespace std;

void printNtoOneBacktracking(int i, int n)
{
  if (i > n)
    return;
  printNtoOneBacktracking(i + 1, n);
  cout << i << endl;
}
int main()
{
  int n;
  cin >> n;

  printNtoOneBacktracking(1, n);
}