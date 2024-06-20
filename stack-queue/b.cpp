#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here

  int q = 0;
  cin >> q;

  while (q--)
  {
    int n, k;
    cin >> n >> k;

    if (n == 1 && k == 1)
    {
      cout << "YES" << endl;
      continue;
    }
    int rem = n - (k + 1);
    vector<int> v;
    int sum = 0;

    for (int i = 1; i <= k; i++)
    {
      sum += i;
      if (rem == sum)
      {
        v.push_back(i);
        break;
      }
      else if (sum > rem)
      {
        break;
      }
      v.push_back(i);
      if (i == (k - 1))
      {
        v.push_back(rem - sum);
        break;
      }
      /* code */
    }
    int s = 0;
    for (int i = 0; i < v.size(); i++)
    {
      s += v[i];
    }

    if (v.size() == k && s == rem)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}
