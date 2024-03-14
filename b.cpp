#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  int q = 0;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> x >> y;

    if (x < 50)
      cout << "Z" << endl;
    else if (x >= 50 && y < 50)
      cout << "F" << endl;
    else
      cout << "A" << endl;
  }
}
