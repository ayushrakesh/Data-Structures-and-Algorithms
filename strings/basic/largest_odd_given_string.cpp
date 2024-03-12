#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string s)
{
  int i = 0;
  int j = s.size() - 1;

  string t = "";
  bool flag = false;

  for (; i <= j;)
  {
    int num = stoi(to_string(s[j]));

    if (num % 2 == 0)
    {
      j--;
    }
    else
    {
      return s.substr(i, j - i + 1);
      break;
      flag = true;
    }
  }
  if (!flag)
  {
    return "";
    // cout << "" << endl;
  }
  return "";
}

int main()
{
  string s;
  cin >> s;

  cout << largestOddNumber(s) << endl;
}