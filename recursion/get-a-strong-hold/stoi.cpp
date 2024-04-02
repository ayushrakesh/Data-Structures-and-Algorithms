#include <bits/stdc++.h>
using namespace std;
pair<int, int> cntDigits(string s)
{

  int cnt = 0;
  bool start = false;

  pair<int, int> p;
  bool updated = false;
  int from = -1;

  for (int i = 0; i < s.size(); i++)
  {
    int ass = (int)s[i];

    if (ass >= 48 && ass <= 57)
    {
      cnt++;

      if (!updated)
      {
        from = i;
        updated = true;
      }
      start = true;
    }

    else
    {
      if (start)
      {
        break;
      }
    }
  }
  return make_pair(from, cnt);
}
void trim(string &s)
{
  s.erase(0, s.find_first_not_of(' '));
}
int atoi(string s)
{
  int sign = 1;
  long n = 0;
  int i = 0;

  while (i < s.length() && s[i] == ' ')
  {
    i++;
    /* code */
  }

  if (s[i] == '-')
  {
    sign = -1;
    i++;
  }
  else if (s[i] == '+')
  {
    i++;
  }

  while (i < s.length())
  {

    if (s[i] <= '9' && s[i] >= '0')
    {

      n = n * 10 + (s[i] - '0');
      // cnt++;
      i++;

      if (n > INT_MAX && sign == -1)
        return INT_MIN;
      else if (n > INT_MAX && sign == 1)
        return INT_MAX;
    }

    return sign * n;
    /* code */
  }

  return sign * n;
}
int main()
{
  string s;
  cin >> s;

  // pair<int, int> p = cntDigits(s);

  // cout << p.first << " " << p.second << endl;

  // cout << atoi(s) << endl;

  cout << atoi(s) << endl;
}