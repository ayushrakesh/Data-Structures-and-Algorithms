#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < (i + 1); j++)
    {
      cout << "*";
    }
    for (int j = 0; j < n - (i + 1); j++)
    {
      /* code */
      cout << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - (i); j++)
    {
      cout << "*";
    }
    for (int j = 0; j < i; j++)
    {
      /* code */
      cout << " ";
    }
    cout << endl;
  }
}