#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - (i); j++)
    {
      char c = 'A' + j + 32;
      cout << c;
    }
    cout << endl;
  }
}