#include <bits/stdc++.h>
using namespace std;

int sumOfWeights(vector<int> v)
{
  int sum = 0;

  for (int i = 0; i < v.size(); i++)
  {
    sum += v[i];
  }
  return sum;
}

int func(vector<int> v, int cap)
{
  int days = 0, load = 0;

  for (int i = 0; i < v.size(); i++)
  {
    load = load + v[i];

    if (load > cap)
    {
      days++;
      load = v[i];
    }
  }
  days++;

  return days;
}
int leastCapacitytoShipPackages(vector<int> v, int days)
{
  int low = *max_element(v.begin(), v.end());
  int high = sumOfWeights(v);

  int ans = high;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (func(v, mid) <= days)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
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
  int days = 0;
  cin >> days;

  cout << leastCapacitytoShipPackages(v, days) << endl;
}