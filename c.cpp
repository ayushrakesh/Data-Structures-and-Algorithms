#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q = 0;
  cin >> q;

  map<char, int> hashing = {
      {'a', 0},
      {'b', 0},
      {'c', 0},
      {'d', 0},
      {'e', 0},
      {'f', 0},
      {'g', 0},
      {'h', 0},
      {'i', 0},
      {'j', 0},
      {'k', 0},
      {'l', 0},
      {'m', 0},
      {'n', 0},
      {'o', 0},
      {'p', 0},
      {'q', 0},
      {'r', 0},
      {'s', 0},
      {'t', 0},
      {'u', 0},
      {'v', 0},
      {'w', 0},
      {'x', 0},
      {'y', 0},
      {'z', 0},
  };

  // for (int i = 0; i < s.size(); i++)
  // {
  //   hashing[s[i] - 'a']++;
  // }

  for (int l = 0; l < q; l++)
  {
    int n = 0;
    cin >> n;

    vector<int> v;
    int a = 0;
    string s = "";

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      v.push_back(a);
    }

    for (int i = 0; i < v.size(); i++)
    {

      for (auto it : hashing)
      {
        if (it.second == v[i])
        {
          it.second++;
          s.push_back(it.first);
          break;
        }
      }
    }

    cout << s << endl;
  }
}