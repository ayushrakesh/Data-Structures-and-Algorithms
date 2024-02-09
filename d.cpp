#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int i = 0; i < q; i++)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;

    int en = 0;
    int st = 0;

    for (int j = 0; j < n; j++)
    {
      if (s[j] == 'B')
      {
        st = j;
        break;
      }
    }

    for (int k = n - 1; k >= 0; k--)
    {
      if (s[k] == 'B')
      {
        en = k;
        break;
      }
    }

    cout << en - st + 1 << endl;
  }
}