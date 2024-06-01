#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int> &candidates, vector<int> &v, int target,
           vector<vector<int>> &ans)
{

  if (ind == candidates.size())
  {
    if (target == 0)
    {
      ans.push_back(v);
    }
    return;
  }

  if (candidates[ind] <= target)
  {
    v.push_back(candidates[ind]);
    solve(ind, candidates, v, target - candidates[ind], ans);
    v.pop_back();
  }

  solve(ind + 1, candidates, v, target, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;

  vector<int> v;

  solve(0, candidates, v, target, ans);
  return ans;
}
int main()
{
  int n;
  int target = 0;
  cin >> n >> target;

  vector<int> v;
  int a = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  vector<vector<int>> res = combinationSum(v, target);

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[0].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}