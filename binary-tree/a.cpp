#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int func(string s)
{
  int n = s.size() - 1;
  int res = 0;
  for (int i = n; i >= 0; i--)
  {
    res +=
  }
}
string convertDateToBinary(string date)
{
  string res = "";
  string year = date.substr(0, 4);
  string mont = date.substr(5, 2);
  string day = date.substr(7, 2);

  int y = stoi(year);
  int m = stoi(mont);
  int d = stoi(day);

  string a = bitset<32>(y).to_string();
  a = a.substr(a.find('1'));
  res += a;

  string b = bitset<32>(m).to_string();
  b = b.substr(b.find('1'));
  res += '-';
  res += b;

  string c = bitset<32>(d).to_string();
  c = c.substr(c.find('1'));
  res += '-';
  res += c;

  return res;
}