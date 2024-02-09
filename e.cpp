#include <bits/stdc++.h>

using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  for (int l = 0; l < q; l++)
  {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a;
    int z = 0;

    vector<int> b;

    for (int i = 0; i < n; i++)
    {
      cin >> z;
      a.push_back(z);
    }

    for (int i = 0; i < m; i++)
    {
      cin >> z;
      b.push_back(z);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    int count = 1;
    int c1 = 0, c2 = 0;

    vector<int> w, v;

    for (int i = 0; i < n; i++)
    {
      if (a[i] <= k)
      {
        w.push_back(a[i]);
      }
    }

    for (int i = 0; i < m; i++)
    {
      if (b[i] <= k)
      {
        v.push_back(b[i]);
      }
    }

    int mini = min(w.size(), v.size());

    for (; i < mini && j < mini;)
    {
      if (w[i] == count)
      {
        c1++;
        count++;
        i++;
      }
      else if (v[j] == count)
      {
        c2++;
        count++;
        j++;
      }
      else
      {
        i++;
        j++;
      }
    }

      if (c1 < k / 2)
    {
      for (; i < w.size(); i++)
      {
        /* code */
        if (w[i] == count)
        {
          count++;
        }
      }
    }

    if (c2 < k / 2)
    {
      for (; j < v.size(); j++)
      {
        /* code */
        if (v[j] == count)
        {
          count++;
        }
      }
    }

    if (count == k)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}