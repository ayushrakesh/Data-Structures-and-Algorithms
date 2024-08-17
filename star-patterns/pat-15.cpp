#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  char c = 'A';

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < (i + 1); j++)
    {
      cout << c;
    }
    c++;
    cout << endl;
  }
}