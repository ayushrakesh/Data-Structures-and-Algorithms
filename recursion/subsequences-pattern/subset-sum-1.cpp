#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &arr, vector<int> &res, int sum)
{
  if (ind == arr.size())
  {
    res.push_back(sum);
    return;
  }

  solve(ind + 1, arr, res, sum + arr[ind]);
  solve(ind + 1, arr, res, sum);
}
vector<int> subsetSums(vector<int> arr, int n)
{
  // Write Your Code here
  vector<int> res;
  int sum = 0;

  solve(0, arr, res, sum);
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
  vector<int> res = subsetSums(v, n);

  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}