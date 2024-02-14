#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  int q = 0;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int n;
    cin >> n;

    if (n == 1)
      cout << 1 << " " << 1 << endl;

    // else if (n % 2 == 0)
    //   cout << n / 2 << " " << n / 2 << endl;
    else
      cout << ceil(n / 2.0) << " " << ceil(n / 3.0) << endl;
  }
}