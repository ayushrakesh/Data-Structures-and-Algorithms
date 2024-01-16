#include <bits/stdc++.h>
using namespace std;
int main()
{
  int q = 0;
  cin >> q;

  while (q != 0)
  {

    int n;
    cin >> n;
    string s;
    cin >> s;
    string f;
    cin >> f;

    int counts = 0, countf = 0;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
      {
        counts++;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (f[i] == '1')
      {
        countf++;
      }
    }
    int ans = 0;
    if (counts <= countf)
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == '0' && f[i] == '1')
        {
          ans++;
        }
      }
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        if (s[i] == '1' && f[i] == '0')
        {
          ans++;
        }
      }
    }

    cout << ans << endl;

    q--;
  }
}
