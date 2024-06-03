#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, vector<int> &v, map<int, int> &mp,
           vector<vector<int>> &res)
{
  if (v.size() == nums.size())
  {
    res.push_back(v);
    return;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (mp[i] == 0)
    {
      v.push_back(nums[i]);
      mp[i] = 1;

      solve(nums, v, mp, res);

      v.pop_back();
      mp[i] = 0;
    }
  }
}
vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> res;
  vector<int> v;
  map<int, int> mp;

  solve(nums, v, mp, res);

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

  vector<vector<int>> res = permute(v);

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[0].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}