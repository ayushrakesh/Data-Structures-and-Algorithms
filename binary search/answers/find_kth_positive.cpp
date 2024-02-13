#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
  int n = arr.size();
  int low = 0, high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    int missing = arr[mid] - (mid + 1);
    if (missing < k)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return high + k + 1;
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
  int k = 0;
  cin >> k;
  cout << findKthPositive(v, k) << endl;
}