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
pair<int, int> giveInteger(string s, int i, int sign)
{

  if (s[i] > 57 || s[i] < 48)
  {
    return make_pair(0, 0);
  }

  pair<int, int> temp = giveInteger(s, i + 1, sign);

  // if(temp.first >INT_MAX && sign==1){
  //   return make_pair(INT_MAX,0);
  // }
  // else if(temp.first >INT_MAX && sign==-1){
  //   return make_pair(INT_MIN,0);
  // }
  return make_pair(temp.first + (s[i] - 48) * pow(10, temp.second), temp.second + 1);
}
int recurSiveAToi(string s)
{
  int l = s.size();
  int i = 0;
  int sign = 1;

  while (i < l && s[i] == ' ')
  {
    /* code */ i++;
  }

  if (s[i] == '+')
  {
    i++;
  }
  else if (s[i] == '-')
  {
    sign = -1;
    i++;
  }
  pair<int, int> temp = giveInteger(s, i, sign);

  if (temp.first > INT_MAX && sign == 1)
  {
    return INT_MAX;
  }
  else if (temp.first > -INT_MIN && sign == -1)
  {
    return INT_MIN;
  }
  return sign * temp.first;
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