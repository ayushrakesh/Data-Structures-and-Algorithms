#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n = 5;

  for (int i = 0; i < n; i++)
  {
    char c = n - (i + 1) + 'A';
    for (int j = 0; j < (i + 1); j++)
    {
      cout << c;
      c++;
    }
    for (int j = 0; j < n - (j + 1); j++)
    {
      cout << " ";
    }
    cout << endl;
  }
}