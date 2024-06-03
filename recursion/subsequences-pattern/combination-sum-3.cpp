#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &v, vector<int> &w,
           vector<vector<int>> &res, int k, int n)
{
  if ((ind == v.size()) && (w.size() != k))
  {
    return;
  }
  if (w.size() == k || ind == v.size())
  {
    if (n == 0)
    {
      res.push_back(w);
    }
    return;
  }

  if (v[ind] <= n)
  {
    w.push_back(v[ind]);
    solve(ind + 1, v, w, res, k, n - v[ind]);
    w.pop_back();
  }

  solve(ind + 1, v, w, res, k, n);
}
vector<vector<int>> combinationSum3(int k, int n)
{

  vector<vector<int>> res;
  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> w;
  // int sum = 0;
  solve(0, v, w, res, k, n);

  return res;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> v;
  int a = 0;

  int m = 0;
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  vector<vector<int>> res = combinationSum3(k, n);

  for (int i = 0; i < res.size(); i++)
  {
    /* code */
    for (int j = 0; j < res[0].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}