#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
  priority_queue<int, vector<int>, greater<int>> p;
  int l;
  KthLargest(int k, vector<int> &nums)
  {
    this->l = k;
    for (int i = 0; i < min(k, (int)nums.size()); i++)
    {
      p.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
      if (nums[i] > p.top())
      {
        p.pop();
        p.push(nums[i]);
      }
    }
  }

  int add(int val)
  {
    if (p.size() < l)
    {
      p.push(val);
      return p.top();
    }
    else if (val > p.top())
    {
      p.pop();
      p.push(val);
      return p.top();
    }
    return p.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */