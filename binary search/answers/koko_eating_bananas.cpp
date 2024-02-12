#include <bits/stdc++.h>
using namespace std;

int func(int mid, vector<int> v)
{
  int timeHrs = 0;

  for (int i = 0; i < v.size(); i++)
  {
    timeHrs = timeHrs + ceil(double(v[i]) / double(mid));
  }
  return timeHrs;
}

int kokoEatingBananas(vector<int> v, int h)
{
  int low = 1;
  int high = *max_element(v.begin(), v.end());
  int ans = h;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    int timeHrs = func(mid, v);

    if (timeHrs <= h)
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
  int h = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }
  cin >> h;

  cout << kokoEatingBananas(v, h) << endl;

  cout << *max_element(v.begin(), v.end());
}