#include <bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s)
{
  int n = s.size();
  int cnt = 0;

  vector<int> arr(3, -1);

  for (int i = 0; i < n; i++)
  {
    arr[s[i] - 'a'] = i;

    if (arr[0] >= 0 && arr[1] >= 0 && arr[2] >= 0)
    {
      int mini = arr[0];
      for (int j = 0; j < 3; j++)
      {
        mini = min(mini, arr[j]);
      }
      cnt = cnt + mini + 1;
    }
  }
  return cnt;
}
int brute(string s)
{
  int n = s.size();
  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    vector<int> arr(3, 0);
    for (int j = i; j < n; j++)
    {
      arr[s[j] - 'a']++;
      cout << s.substr(i, j - i + 1) << endl;
      if ((arr[0] >= 1) && (arr[1] >= 1) && (arr[2] >= 1))
      {
        cnt++;
      }
    }
  }
  return cnt;
}

int main()
{
  string s;
  cin >> s;
  cout << numberOfSubstrings(s) << endl;
}