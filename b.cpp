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
    set<int, greater<int>> s;

    for (int i = n - 1; i >= 0; i--)
    {
      int temp = v[i] + i + 1;
      // vector<int>::iterator it = v.begin() + i;
      int index = i;

      for (int j = n - 1; j >= 0; j--)
      {
        /* code */
        if ((v[j] + j + 1) > temp)
        {
          temp = v[j] + j + 1;
          // it = v.begin() + j;
          index = j;
        }
      }

      s.insert(temp);
      remove(v.begin() + index, v.begin() + index + 1, v[index]);

      // v.erase(remove(v.begin(), v.end(), temp), v.end());

      // v.erase(v.begin() + index, v.begin() + index + 1);
    }

    for (auto it2 : s)
    {
      cout << it2 << " ";
    }
  }
}