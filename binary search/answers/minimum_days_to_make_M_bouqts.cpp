#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> v, int days, int m, int k)
{
  int bouq = 0;
  int count = 0;

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] <= days)
      count++;
    else
    {
      bouq = bouq + count / k;
      count = 0;
    }
  }
  bouq = bouq + count / k;

  if (bouq >= m)
    return true;
  else
    return false;
}

int mimimumDaysToMakeMBouqts(vector<int> v, int m, int k)
{
  if (v.size() < m * k)
    return -1;

  int low = *min_element(v.begin(), v.end());
  int high = *max_element(v.begin(), v.end());
  int ans = high;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (possible(v, mid, m, k))
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
  int m, k;
  cin >> m >> k;

  cout << mimimumDaysToMakeMBouqts(v, m, k) << endl;
}