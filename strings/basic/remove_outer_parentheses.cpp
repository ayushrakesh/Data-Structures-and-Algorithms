#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;

  bool first = false;
  int count = 0;
  int count2 = 0;
  string t = "";

  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '(' && !first)
    {
      // count++;
      first = true;
    }
    else if (s[i] == '(' && first)
    {
      t.append("(");
      // cout << s[i];
      count++;
    }
    else
    {
      if (count != count2)
      {
        t.append(")");
        // cout << s[i];
        count2++;
      }
      else
      {
        first = false;
        count = 0, count2 = 0;
      }
    }
  }
  cout << t << endl;
}