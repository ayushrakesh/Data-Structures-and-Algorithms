#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int target)
{
  int low = 0;
  int high = v.size() - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (v[mid] == target)
      return mid;

    else if (target > v[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int binarySearchRec(vector<int> v, int low, int high, int target)
{
  int mid = (low + high) / 2;
  if (low > high)
    return -1;

  else if (target == v[mid])
    return mid;
  else if (target > v[mid])
    return binarySearchRec(v, mid + 1, high, target);

  else
    return binarySearchRec(v, low, mid - 1, target);
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

  cout << binarySearch(v, target) << endl;
  cout << binarySearchRec(v, 0, n - 1, target) << endl;
}