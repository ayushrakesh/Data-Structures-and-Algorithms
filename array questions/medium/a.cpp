#include <bits/stdc++.h>
using namespace std;
void dutchNationalFlag(vector<int> &v)
{
  int n = v.size();

  int mid = 0, high = n - 1, low = 0;

  while (mid <= high)
  {
    if (v[mid] == 0)
    {
      swap(v[mid], v[low]);
      low++;
      mid++;
    }
    else if (v[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(v[mid], v[high]);
      high--;
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
void mooreVotingAlgo(vector<int> &v)
{
  int cnt = 0;
  int curr = NULL;

  for (int i = 0; i < v.size(); i++)
  {
    if (cnt == 0)
    {
      curr = v[i];
    }
    else
    {
      if (v[i] == curr)
      {
        cnt++;
      }
      else
      {
        cnt--;
      }
    }
  }
  cout << "Majority element is " << curr << endl;
}
void mooreVotingAlgoMap(vector<int> &v)
{
  map<int, int> mp;
  int n = v.size();

  for (int i = 0; i < v.size(); i++)
  {
    mp[v[i]]++;
  }

  for (auto it : mp)
  {
    if (it.second > (n / 2))
    {
      cout << it.first << endl;
      break;
    }
  }
}
void maxSubArraySum(vector<int> &v)
{
  int maxi = INT_MIN;
  int n = v.size();

  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += v[j];
      maxi = max(maxi, sum);
    }
  }
  cout << maxi << endl;
}

int main()
{
  vector<int> v = {2, 2, 0, 0, 1, 1, 2, 2, 2, 2};
  dutchNationalFlag(v);

  vector<int> w = {2, 2, 0, 0, 1, 1, 2, 2, 2, 2};
  mooreVotingAlgoMap(w);

  vector<int> q = {1, 2, 3, -2, -1};
  maxSubArraySum(q);
}