#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  int k = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < (i + 1); j++)
    {
      char c = 'A' + j + 32;
      cout << c;
    }
    cout << endl;
  }
}