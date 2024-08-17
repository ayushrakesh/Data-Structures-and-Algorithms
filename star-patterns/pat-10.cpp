#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n = 5;
  bool b = false;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < (i + 1); j++)
    {
      if (!b)
      {
        cout << 1;
        b = true;
      }
      else
      {
        cout << 0;
        b = false;
      }
    }
    for (int j = 0; j < n - (i + 1); j++)
    {
      cout << " ";
    }
    cout << endl;
    b = !b;
  }
}