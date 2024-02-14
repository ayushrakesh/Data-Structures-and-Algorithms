#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int p = 0; p < q; p++)
  {
    int n;
    cin >> n;
    string s = "";
    // int sum = 3;
    string t = "Aabcdefghijklmnopqrstuvwxyz";

    if (n <= 28)
    {
      cout << "aa" << t[n - 2] << endl;
    }
    else if (n > 28 && n <= 53)
    {
      cout << "a" << t[n - 27] << "z" << endl;
    }
    else
    {
      cout << t[n - 52] << "zz" << endl;
    }
  }
}