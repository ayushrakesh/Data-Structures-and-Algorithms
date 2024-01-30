#include <bits/stdc++.h>
using namespace std;

// Better solution -> n*logn
int longestConsecutiveSeq1(vector<int> &v)
{
  int longestCnt = 0;
  int currCnt = 0;
  int lastSmallest = INT_MIN;

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    // currCnt = 1;

    if (v[i] - 1 == lastSmallest)
    {
      currCnt++;
      lastSmallest = v[i];
    }
    else if (v[i] != lastSmallest)
    {
      currCnt = 1;
      lastSmallest = v[i];
    }

    longestCnt = max(longestCnt, currCnt);
  }

  return longestCnt;
}

// Optimal solution - using set
int longestConsecutiveSeq2(vector<int> v)
{
  unordered_set<int> s;

  int longest = 1;

  for (int i = 0; i < v.size(); i++)
  {
    s.insert(v[i]);
  }

  for (auto it : s)
  {
    if (s.find(it - 1) == s.end())
    {
      int currCnt = 1;
      int x = it;
      while (s.find(x + 1) != s.end())
      {
        /* code */
        currCnt++;
        x = x + 1;
      }
      longest = max(longest, currCnt);
    }
  }
  return longest;
}
int main()
{
  int n;
  cin >> n;
  int a;

  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }

  cout << longestConsecutiveSeq1(v) << endl;
  cout << longestConsecutiveSeq2(v) << endl;
}