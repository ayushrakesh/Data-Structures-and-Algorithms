#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> v, int target)
{
  int n = v.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    /* code */

    int mid = (low + high) / 2;

    if (v[mid] > target)
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
  int target = 0;
  cin >> target;
  cout << upperBound(v, target) << endl;
}