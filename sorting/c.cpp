#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &v, int low, int high, int mid)
{
  vector<int> temp;
  int left = low;
  int right = mid + 1;

  while (left <= mid && right <= high)
  {
    if (v[left] <= v[right])
    {
      temp.push_back(v[left]);
      left++;
    }
    else
    {
      temp.push_back(v[right]);
      right++;
    }
  }

  while (left <= mid)
  {
    temp.push_back(v[left]);
    left++;
  }

  while (right <= high)
  {
    temp.push_back(v[right]);
    right++;
  }

  for (int i = low; i <= high; i++)
  {
    v[i] =
  }
}
void mergeRecur(vector<int> &v, int low, int high)
{
  if (low >= high)
    return;

  int mid = (low + high) / 2;

  mergeRecur(v, low, mid);
  mergeRecur(v, mid + 1, high);

  merge(v, low, high, mid);
}
int main()
{
  vector<int> v = {1, 1, 5, 4, 0, 8, 7, 5, 2};

  mergeRecur(v, 0, v.size() - 1);

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}