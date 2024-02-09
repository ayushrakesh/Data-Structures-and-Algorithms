
#include <bits/stdc++.h>
using namespace std;

int minimumInRotatedSorted(vector<int> v)
{
  int n = v.size();
  int low = 0;
  int high = n - 1;
  int mini = INT_MAX;

  while (low <= high)
  {
    /* code */
    int mid = (low + high) / 2;

    if (v[low] <= v[mid])
    {
      mini = min(mini, v[low]);
      low = mid + 1;
    }
    else
    {
      mini = min(mini, v[mid]);
      high = mid - 1;
    }
  }
  return mini;
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

  cout << minimumInRotatedSorted(v) << endl;
}