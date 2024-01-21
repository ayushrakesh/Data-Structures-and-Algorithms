#include <bits/stdc++.h>
using namespace std;

// optimal solution for positives numbers array only
int longestSubarray(vector<int> v, int k)
{
  int maxLength = 0;
  int sum = v[0];
  int left = 0, right = 0;
  int n = v.size();

  while (right < n)
  {

    while (left <= right && sum > k)
    {
      sum = sum - v[left];
      left++;
    }
    if (sum == k)
    {
      maxLength = max(maxLength, right - left + 1);
    }
    right++;
    if (right < n)
    {
      sum = sum + v[right];
    }
  }
  return maxLength;
}

// optimal solution for positives + negatives element in array
int longestSubarrayNeg(vector<int> v, int k)
{
  int maxLength = 0;
  int sum = 0;
  map<int, int> preSumMap;

  for (int i = 0; i < v.size(); i++)
  {
    sum = sum + v[i];
    if (sum == k)
    {

      maxLength = max(maxLength, i + 1);
    }

    int rem = sum - k;

    if (preSumMap.find(rem) != preSumMap.end())
    {
      int len = i - preSumMap[rem];
      maxLength = max(maxLength, len);
    }

    if (preSumMap.find(sum) == preSumMap.end())
    {
      preSumMap[sum] = i;
    }
  }
  return maxLength;
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
  int k;
  cin >> k;

  cout << longestSubarray(v, k) << endl;
  cout << longestSubarrayNeg(v, k) << endl;
}