#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> v)
{
  int n = v.size();

  if (n == 1)
    return 0;
  if (v[0] > v[1])
    return 0;
  if (v[n - 1] > v[n - 2])
    return n - 1;

  int low = 1, high = n - 2;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
    {
      return mid;
    }
    else if (v[mid] > v[mid - 1])
      low = mid + 1;
    else
    {
      high = mid - 1;
    }
  }

  return -1;
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

  cout << peakElement(v) << endl;
}