#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

  vector<int> res;
  unordered_map<int, int> mp;

  for (int i = 0; i < nums2.size(); i++)
  {
    mp[nums2[i]] = i;
  }

  for (int i = 0; i < nums1.size(); i++)
  {
    int index = mp[nums1[i]];

    res.push_back(-1);

    for (int j = index + 1; j < nums2.size(); j++)
    {
      if (nums2[j] > nums1[i])
      {
        res.pop_back();
        res.push_back(nums2[j]);
        break;
      }
    }
  }
  return res;
}

int main()
{
}