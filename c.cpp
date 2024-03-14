#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int o = 0; o < q; o++)
  {
    int n;
    cin >> n;
    vector<int> v;
    int a = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      v.push_back(a);
    }

    int index = 0;
    vector<int> res;

    int cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
      if (v[i] == 0)
      {
        v[i] = 1;
        cnt0++;
      }
      else
      {
        break;
      }
    }

    int cnt1 = 0;
    int maxi = 0;
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
      if (v[i] == 1)
      {
        cnt1++;
        maxi = max(maxi, cnt1);
      }
      else
      {
        cnt1 = 0;
        // break;
      }
    }

    res.push_back(maxi);

    cout << *max_element(res.begin(), res.end()) << endl;
  }
}