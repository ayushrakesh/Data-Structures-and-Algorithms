#include <bits/stdc++.h>
using namespace std;

int firstOccur(vector<int> v, int target)
{
  int n = v.size();
  int first = -1;
  int low = 0, high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (v[mid] == target)
    {
      first = mid;
      high = mid - 1;
    }
    else if (v[mid] > target)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return first;
}

int lastOccur(vector<int> v, int target)
{
  int n = v.size();
  int low = 0, high = n - 1;
  int last = -1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (v[mid] == target)
    {
      last = mid;
      low = mid + 1;
    }

    else if (v[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return last;
}
pair<int, int> firstLastOccur(vector<int> v, int target)
{
  // int n = v.size();
  pair<int, int> p;

  int first = firstOccur(v, target);

  if (first == -1)
  {
    return make_pair(-1, -1);
  }

  return make_pair(first, lastOccur(v, target));
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

  pair<int, int> p = firstLastOccur(v, target);
  cout << p.first << " " << p.second << endl;
}