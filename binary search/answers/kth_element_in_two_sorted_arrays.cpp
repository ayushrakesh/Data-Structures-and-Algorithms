#include <bits/stdc++.h>
using namespace std;

int kthElementInSortedArrays(vector<int> &v, vector<int> &w, int k)
{
  int n1 = v.size();
  int n2 = w.size();

  if (n2 < n1)
    return kthElementInSortedArrays(w, v, k);

  int left = k;
  int low = max(0, k - n2), high = min(k, n1);

  int n = n1 + n2;

  while (low <= high)
  {
    /* code */
    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;

    int mid1 = (low + high) / 2;
    int mid2 = left - mid1;

    if (n1 - mid1 >= 1)
      r1 = v[mid1];
    if (n2 - mid2 >= 1)
      r2 = w[mid2];

    if (mid1 >= 1)
      l1 = v[mid1 - 1];
    if (mid2 >= 1)
      l2 = w[mid2 - 1];

    if (l1 <= r2 && l2 <= r1)
    {
      if (n % 2 == 1)
        return max(l1, l2);
      else
        return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
    }
    else if (l1 > r2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }

  return 0;
}

int main()
{
  int n1, n2;
  cin >> n1 >> n2;

  vector<int> v;
  int a = 0;
  vector<int> w;

  for (int i = 0; i < n1; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  for (int i = 0; i < n2; i++)
  {
    cin >> a;
    w.push_back(a);
  }

  int k = 0;
  cin >> k;

  cout << kthElementInSortedArrays(v, w, k) << endl;
}