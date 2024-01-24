#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> v)
{
  int maxi = INT_MIN;
  int sum = 0;

  for (int i = 0; i < v.size(); i++)
  {
    sum += v[i];
    maxi = max(maxi, sum);

    if (sum < 0)
      sum = 0;
  }
  return maxi;
}
int main()
{
  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v.push_back(a);
  }

  cout << maxSubArraySum(v) << endl;
}