#include <bits/stdc++.h>
using namespace std;

void dutchNationalFlagAlgo(vector<int> &v)
{
  int low = 0, mid = 0;
  int high = v.size() - 1;

  while (mid <= high)
  {
    if (v[mid] == 0)
    {
      swap(v[low], v[mid]);
      low++;
      mid++;
    }
    else if (v[mid] == 1)
    {
      mid++;
    }
    else if (v[mid] == 2)
    {
      swap(v[mid], v[high]);
      high--;
    }
  }
}
int main()
{
  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v.push_back(a);
  }

  dutchNationalFlagAlgo(v);

  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
}