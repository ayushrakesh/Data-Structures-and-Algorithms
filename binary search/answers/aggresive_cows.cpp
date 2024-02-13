#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> v, int d, int cows)
{
  int placedCows = 1, lastCow = v[0];

  for (int i = 1; i < v.size(); i++)
  {
    if (v[i] - lastCow >= d)
    {
      placedCows++;
      lastCow = v[i];
    }
  }
  return placedCows >= cows;
}

int aggresiveCows(vector<int> &v, int cows)
{
  int n = v.size();
  sort(v.begin(), v.end());

  int low = 1, high = v[n - 1] - v[0];
  int ans = 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (canWePlace(v, mid, cows))
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
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
  int cows = 0;
  cin >> cows;

  cout << aggresiveCows(v, cows) << endl;
}