#include <bits/stdc++.h>
using namespace std;

int mooreVotingAlgo(vector<int> v)
{
  int ele;
  int count = 0;

  for (int i = 0; i < v.size(); i++)
  {
    /* code */
    if (count == 0)
    {
      count = 1;
      ele = v[i];
    }
    else if (v[i] == ele)
    {
      count++;
    }
    else
    {
      count--;
    }
  }

  int count1 = 0;

  // Optional -> only if we are not sure that majority element exists or not
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == ele)
      count1++;
  }

  if (count1 > (v.size() / 2))
  {
    return ele;
  }
  else
  {
    return -1;
  }
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

  cout << mooreVotingAlgo(v) << endl;
}