#include <bits/stdc++.h>
using namespace std;

int searchRotatedSorted(vector<int> v, int target)
{
  int n = v.size();
  int low = 0, high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (v[mid] == target)
      return mid;

    if (v[low] <= v[mid])
    {
      if (target >= v[low] && target <= v[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (target >= v[mid] && target <= v[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return -1;
}

bool searchRotatedSortedDuplicates(vector<int> nums, int target)
{
  int n = nums.size();
  int low = 0, high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (nums[mid] == target)
      return true;

    // Shrinking the search space in case of duplicates
    if (nums[mid] == nums[low] && nums[mid] == nums[high])
    {
      low++;
      high--;
      continue;
    }
    ////////////////////////////////////////////////

    if (nums[low] <= nums[mid])
    {
      if (target >= nums[low] && target <= nums[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else
    {
      if (target >= nums[mid] && target <= nums[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return false;
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

  cout << searchRotatedSortedDuplicates(v, target) << endl;
}