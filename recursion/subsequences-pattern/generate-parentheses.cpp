#include <bits/stdc++.h>
using namespace std;

void solve(string &s, vector<string> &v, int l, int &leftCnt, int &rightCnt)
{
  if (s.size() == l)
  {
    if (leftCnt == rightCnt)
    {
      v.push_back(s);
    }
    return;
  }

  if (leftCnt < (l / 2))
  {
    s.push_back('(');
    leftCnt++;
    solve(s, v, l, leftCnt, rightCnt);
    leftCnt--;
    s.pop_back();
  }

  if (rightCnt < leftCnt)
  {
    s.push_back(')');
    rightCnt++;
    solve(s, v, l, leftCnt, rightCnt);
    rightCnt--;
    s.pop_back();
  }
}
vector<string> generateParenthesis(int l)
{
  vector<string> v;
  string s = "";
  int leftCnt = 0;
  int rightCnt = 0;

  solve(s, v, l, leftCnt, rightCnt);

  return v;
}
int main()
{
  int n;
  cin >> n;

  vector<string> v = generateParenthesis(2 * n);

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}