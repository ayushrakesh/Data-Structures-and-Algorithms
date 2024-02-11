
#include <bits/stdc++.h>
using namespace std;

// Both for unique and duplicates element
int howManyTimesArrayRotated(vector<int> v)
{
  int n = v.size();
  int low = 0;
  int high = n - 1;
  int mini = INT_MAX;
  int index = -1;

  while (low <= high)
  {
    /* code */
    int mid = (low + high) / 2;

    if (v[low] <= v[mid])
    {
      mini = min(mini, v[low]);

      if (mini == v[low])
      {
        index = low;
      }
      low = mid + 1;
    }
    else
    {
      mini = min(mini, v[mid]);

      if (mini == v[mid])
      {
        index = mid;
      }
      high = mid - 1;
    }
  }
  return index;
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

  cout << howManyTimesArrayRotated(v) << endl;
}