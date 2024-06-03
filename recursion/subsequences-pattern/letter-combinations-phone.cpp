#include <bits/stdc++.h>
using namespace std;

void solve(int ind, string digits, string &s, vector<string> &res)
{
  if (ind == digits.size())
  {
    res.push_back(s);
    return;
  }

  if (digits[ind] <= '6' && digits[ind] >= '2')
  {
    s.push_back(digits[ind] + 47 + (digits[ind] - '2') * 2);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 48 + (digits[ind] - '2') * 2);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 49 + (digits[ind] - '2') * 2);
    solve(ind + 1, digits, s, res);

    s.pop_back();
  }
  else if (digits[ind] == '7')
  {
    s.push_back(digits[ind] + 57);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 58);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 59);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 60);
    solve(ind + 1, digits, s, res);

    s.pop_back();
  }
  else if (digits[ind] == '9')
  {
    s.push_back(digits[ind] + 62);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 63);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 64);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 65);
    solve(ind + 1, digits, s, res);

    s.pop_back();
  }
  else
  {
    s.push_back(digits[ind] + 60);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 61);
    solve(ind + 1, digits, s, res);

    s.pop_back();

    s.push_back(digits[ind] + 62);
    solve(ind + 1, digits, s, res);

    s.pop_back();
  }
}
vector<string> letterCombinations(string digits)
{

  vector<string> res;
  string s = "";

  if (digits == "")
  {
    return {};
  }
  solve(0, digits, s, res);
  return res;
}

int main()
{
  string s;
  cin >> s;

  vector<string> res = letterCombinations(s);

  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}