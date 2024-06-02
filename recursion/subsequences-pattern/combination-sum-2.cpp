#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &candidates, vector<int> &v,
           vector<vector<int>> &res, int target)
{

  if (target == 0)
  {
    res.push_back(v);
    return;
  }

  for (int i = ind; i < candidates.size(); i++)
  {
    if ((i > ind) && (candidates[i] == candidates[i - 1]))
      continue;
    if (candidates[i] > target)
      break;

    v.push_back(candidates[i]);
    solve(i + 1, candidates, v, res, target - candidates[i]);
    v.pop_back();
  }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  vector<vector<int>> res;
  vector<int> v;

  sort(candidates.begin(), candidates.end());
  solve(0, candidates, v, res, target);
  return res;
}
int main()
{
  int n, target;
  cin >> n >> target;
  vector<int> v;
  int a = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  vector<vector<int>> res = combinationSum2(v, target);

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[0].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}