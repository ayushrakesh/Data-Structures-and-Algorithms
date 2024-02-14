#include <bits/stdc++.h>
using namespace std;

double medianOfTwoSortedArrays(vector<int> &v, vector<int> &w)
{
  int n1 = v.size();
  int n2 = w.size();

  int n = n1 + n2;

  int ind2 = n / 2;
  int ind1 = ind2 - 1;

  int i = 0, j = 0, count = 0;
  int ind1el = -1, ind2el = -1;

  while (i < n1 && j < n2)
  {
    /* code */
    if (v[i] < w[j])
    {
      if (count == ind1)
        ind1el = v[i];
      if (count == ind2)
        ind2el = v[i];
      count++;
      i++;
    }
    else
    {
      if (count == ind1)
        ind1el = w[j];
      if (count == ind2)
        ind2el = w[j];
      count++;
      j++;
    }
  }

  while (i < n1)
  {
    if (count == ind1)
      ind1el = v[i];
    if (count == ind2)
      ind2el = v[i];
    count++;
    i++;
    /* code */
  }
  while (j < n2)
  {
    if (count == ind1)
      ind1el = w[j];
    if (count == ind2)
      ind2el = w[j];
    count++;
    j++;
    /* code */
  }

  if (n % 2 == 1)
  {
    return ind2el;
  }
  else
  {
    return (double)((double)ind1el + (double)ind2el) / 2.0;
  }
}
double medianOfTwoSortedArraysOptimal(vector<int> &v, vector<int> &w)
{
  int n1 = v.size();
  int n2 = w.size();

  if (n2 < n1)
    return medianOfTwoSortedArraysOptimal(w, v);

  int left = (n1 + n2 + 1) / 2;
  int low = 0, high = n1;

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
  vector<int> w;
  int a = 0, b = 0;

  for (int i = 0; i < n1; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  for (int i = 0; i < n2; i++)
  {
    cin >> b;
    w.push_back(b);
  }

  // cout << medianOfTwoSortedArrays(v, w) << endl;
  cout << medianOfTwoSortedArraysOptimal(v, w) << endl;
}