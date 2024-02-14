#include <bits/stdc++.h>
using namespace std;

int noOfStud(vector<int> v, int pages)
{
  int stud = 1, currentPages = 0;

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] + currentPages <= pages)
    {
      currentPages += v[i];
    }
    else
    {
      stud++;
      currentPages = v[i];
    }
  }
  return stud;
}

int bookAllocationProblem(vector<int> v, int m)
{
  int n = v.size();

  int low = *max_element(v.begin(), v.end());
  int high = accumulate(v.begin(), v.end(), 0);

  int ans = high;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    int students = noOfStud(v, mid);

    if (students <= m)
    {
      ans = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return ans;
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
  int m = 0;
  cin >> m;

  cout << bookAllocationProblem(v, m) << endl;
}