#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
  vector<int> res;
  stack<int> st;

  int n = nums.size();
  int arr[n];

  for (int i = 2 * nums.size() - 1; i >= 0; i--)
  {
    while (!st.empty() && st.top() <= nums[i % n])
    {
      st.pop();
    }
    if (i < nums.size())
    {
      if (!st.empty())
      {
        arr[i] = st.top();
      }
      else
      {
        arr[i] = -1;
      }
    }
    st.push(nums[i % n]);
  }

  for (int i = 0; i < n; i++)
  {
    res.push_back(arr[i]);
  }
  return res;
}

int main()
{
}