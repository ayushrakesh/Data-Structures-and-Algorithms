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
vector<int> maxSubArraySumPrint(vector<int> v)
{
  int maxi = INT_MIN;
  int sum = 0;
  int start = -1, ansStart = -1, ansEnd = -1;

  for (int i = 0; i < v.size(); i++)
  {
    if (sum == 0)
    {
      start = i;
    }
    sum += v[i];
    if (sum > maxi)
    {
      maxi = sum;
      ansStart = start;
      ansEnd = i;
    }
    // maxi = max(maxi, sum);

    if (sum < 0)
      sum = 0;
  }

  return {ansStart, ansEnd};
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