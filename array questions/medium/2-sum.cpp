#include <bits/stdc++.h>
using namespace std;

// Optimal for returning indexes
string twoSumV1(vector<int> v, int target)
{
  map<int, int> mp;

  for (int i = 0; i < v.size(); i++)
  {
    int a = v[i];
    int more = target - a;

    if (mp.find(more) != mp.end())
    {
      return "YES";
    }
    mp[a] = i;
  }
  return "NO";
}

// Optimal for printing "YEs" or "NO"
string twoSumV2(vector<int> v, int target)
{
  vector<int> res;

  sort(v.begin(), v.end());

  int left = 0, right = v.size() - 1;

  while (left < right)
  {
    /* code */

    if (v[left] + v[right] == target)
    {
      return "YES";
    }
    else if (v[left] + v[right] < target)
    {
      left++;
    }
    else
    {
      right--;
    }
  }
  return "NO";
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

  int target = 0;
  cin >> target;

  cout << twoSumV2(v, target) << endl;
}