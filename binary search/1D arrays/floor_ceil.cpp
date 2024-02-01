#include <bits/stdc++.h>
using namespace std;
int floorValue(vector<int> v, int target)
{
  int n = v.size();
  int ans = -1;

  int low = 0, high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (v[mid] <= target)
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  if (ans == -1)
  {
    return ans;
  }
  return v[ans];
}

int main()
{
  int n;
  cin >> n;
  int a;

  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }
  int target = 0;
  cin >> target;
  cout << floorValue(v, target) << endl;
}