#include <bits/stdc++.h>
using namespace std;
int removeElement(vector<int> &nums, int val)
{
  int i = 0;
  for (int j = nums.size() - 1; j >= 0; j--)
  {
    if (nums[j] != val)
    {
      i = j;
      break;
    }
  }

  if (i == 0)
  {
    return 1;
  }
  int j = i - 1;

  for (; j >= 0; j--)
  {
    /* code */
    if (nums[j] == val)
    {
      nums[i + 1] = nums[j];
      i--;
    }
  }

  int count = 0;

  for (int k = 0; k < nums.size(); k++)
  {
    if (nums[k] != val)
    {
      count++;
    }
  }
  return count;
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
  int val = 0;
  cin >> val;

  cout << removeElement(v, val);

  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
}