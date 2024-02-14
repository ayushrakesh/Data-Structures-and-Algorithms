#include <bits/stdc++.h>
using namespace std;
int main()
{
  int q = 0;
  cin >> q;

  for (int l = 0; l < q; l++)
  {
    int n = 0;
    cin >> n;

    vector<int> v;
    int a = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      sum += a;
      v.push_back(a);
    }

    if (n == 1)
    {
      cout << "YES" << endl;
      continue;
      // return 0;
    }
    int req = sum / n;
    int flag = 0;

    long long excess = 0;

    for (int i = 0; i < n; i++)
    {
      if (v[i] >= req)
      {
        excess += (v[i] - req);
      }
      else
      {
        int req_amt = req - v[i];
        if (excess >= req_amt)
        {
          excess -= req_amt;
        }
        else
        {
          cout << "NO" << endl;
          flag = true;
          break;
        }
      }
    }

    if (!flag)
    {

      cout << "YES" << endl;
    }
    // return;
  }
}
