#include <bits/stdc++.h>
using namespace std;

int countSubarraysSumK(vector<int> v, int k)
{
  int res = 0;
  int prefSum = 0;

  unordered_map<int, int> mmp;

  mmp[0] = 1;

  for (int i = 0; i < v.size(); i++)
  {
    prefSum += v[i];
    res += mmp[prefSum - k];
    mmp[prefSum]++;
  }

  return res;
}
int main()
{
  int n;
  cin >> n;
  int a = 0;
  // cin >> a;
  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  int k = 0;
  cin >> k;
  cout << countSubarraysSumK(v, k) << endl;
}