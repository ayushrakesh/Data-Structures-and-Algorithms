#include <bits/stdc++.h>
using namespace std;
int main()
{
  int q = 0;
  cin >> q;

  while (q != 0)
  {
    vector<pair<int, int>> v;
    // vector<pair<int, int>> v2;

    for (int i = 0; i < 4; i++)
    {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }

    for (int i = 1; i <= 3; i++)
    {
      if (v[i].first == v[0].first)
      {
        int base = abs(v[0].first - v[i].first);
        int height = 0;
        if (i == 3)
        {

          height = abs(v[0].second - v[i - 1].second);
        }
        else
        {
          height = abs(v[0].second - v[i + 1].second);
        }
        int area = 0.5 * (base * height);

        cout << area << endl;
        return 0;
      }
    }

    q--;
  }
}