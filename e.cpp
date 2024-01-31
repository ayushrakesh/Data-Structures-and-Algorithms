#include <bits/stdc++.h>
using namespace std;

int maxProductDifference(vector<int> &nums, int k)
{

  int res = 0;
  int n = nums.size();

  for (int i = 0; i < n; i++)
  {
    /* code */
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += nums[j];
      if (sum == k)
      {
        res++;
      }
    }
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;

  int a;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }
  int k = 0;
  cin >> k;

  cout << maxProductDifference(v, k) << endl;
}