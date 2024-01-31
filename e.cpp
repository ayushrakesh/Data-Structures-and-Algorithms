#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int h = 0; h < q; h++)
  {
    int n, k;
    cin >> n >> k;

    vector<int> res;

    for (int i = 0; i < k; i++)
    {
      res.push_back(i + 1);
    }

    int temp = k + 2;
    int tem = k + 1;

    for (int i = res.size(); i < n; i++)
    {
      if (temp <= n)
      {
        res.push_back(temp);
        temp = temp + 2;
      }
      else
      {
        break;
      }
    }

    for (int i = res.size(); i < n; i++)
    {
      /* code */
      if (tem <= n)
      {
        res.push_back(tem);
        tem = tem + 2;
      }
      else
      {
        break;
      }
    }

    for (int i = 0; i < res.size(); i++)
    {
      cout << res[i] << " ";
    }
  }
}