#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &v, string &s, int N)
{

  if (s.size() == N)
  {
    v.push_back(s);
    return;
  }

  if (s[s.size() - 1] == '0')
  {
    s.push_back('0');
    solve(v, s, N);

    s.pop_back();

    s.push_back('1');
    solve(v, s, N);
    s.pop_back();
  }

  else
  {
    s.push_back('0');
    solve(v, s, N);
    s.pop_back();
  }
}

vector<string> generateString(int N)
{

  vector<string> v;
  string s = "0";

  solve(v, s, N);
  s = "1";
  solve(v, s, N);
  return v;
}

int main()
{
  int n;
  cin >> n;

  vector<string> ans = generateString(n);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}