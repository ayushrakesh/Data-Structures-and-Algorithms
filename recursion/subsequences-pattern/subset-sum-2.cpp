#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &nums, vector<int> &v, vector<vector<int>> &res)
{
  res.push_back(v);

  for (int i = ind; i < nums.size(); i++)
  {
    if (i != ind && nums[i] == nums[i - 1])
    {
      continue;
    }
    v.push_back(nums[i]);
    solve(i + 1, nums, v, res);
    v.pop_back();
  }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  vector<int> v;
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  solve(0, nums, v, res);
  return res;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  int a = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  vector<vector<int>> res = subsetsWithDup(v);

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[0].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}