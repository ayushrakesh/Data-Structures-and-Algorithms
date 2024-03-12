#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
  int end = 0, start = 0;
  int count = 0;

  vector<int> lens;

  for (int i = 0; i < strs.size(); i++)
  {
    lens.push_back(strs[i].length());
  }

  int mini = *min_element(lens.begin(), lens.end());
  int minIndex = distance(lens.begin(), min_element(lens.begin(), lens.end()));

  for (int i = 0; i < strs.size(); i++)
  {
    if (strs[i].size() == mini)
    {
      if (minIndex == 0 && strs[i] == strs[i + 1])
        return strs[i];
      else if (minIndex == lens.size() - 1 && strs[i] == strs[i - 1])
        return strs[i];
      else
      {
        return strs[i];
      }
    }
  }
  return "";
}

int main()
{
  vector<string> strs;
  int n = 0;
  cin >> n;

  string s;

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    strs.push_back(s);
    /* code */
  }

  cout << longestCommonPrefix(strs) << endl;
}