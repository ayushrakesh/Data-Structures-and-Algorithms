#include <bits/stdc++.h>
using namespace std;
int characterReplacement(string s, int k)
{
  int n = s.size();
  int maxlen = 0;
  int left = 0, right = 0;
  int maxfre = 0;
  vector<int> arr(26, 0);

  while (right < n)
  {
    arr[s[right] - 'A']++;
    maxfre = max(maxfre, arr[s[right] - 'A']);

    if ((right - left + 1 - maxfre) > k)
    {
      arr[s[left] - 'A']--;
      maxfre = max(maxfre, arr[s[left] - 'A']);
      left++;
    }
    if ((right - left + 1 - maxfre) <= k)
    {
      maxlen = max(maxlen, right - left + 1);
    }
    right++;
  }
  return maxlen;
}
int better(string s, int k)
{
  int n = s.size();
  int maxlen = 0;
  int left = 0, right = 0;
  int maxfre = 0;
  vector<int> arr(26, 0);

  while (right < n)
  {
    arr[s[right] - 'A']++;

    maxfre = max(maxfre, arr[s[right] - 'A']);

    while ((right - left + 1 - maxfre) > k)
    {
      arr[s[left] - 'A']--;
      maxfre = 0;
      for (int i = 0; i < n; i++)
      {
        maxfre = max(maxfre, arr[s[i] - 'A']);
      }
      left++;
    }
    if ((right - left + 1 - maxfre) <= k)
    {
      maxlen = max(maxlen, right - left + 1);
    }
    right++;
  }
  return maxlen;
}
int brute(string s, int k)
{
  int n = s.size();
  int maxlen = 0;
  int maxfre = 0;

  for (int i = 0; i < n; i++)
  {
    vector<int> arr(26, 0);

    for (int j = i; j < n; j++)
    {
      arr[s[j] - 'A']++;
      maxfre = max(maxfre, arr[s[j] - 'A']);

      if ((j - i + 1 - maxfre) <= k)
      {
        maxlen = max(maxlen, j - i + 1);
      }
      else
      {
        break;
      }
    }
  }
  return maxlen;
}

int main()
{
  // int k;
  // cin >> k;
  string s;
  cin >> s;
  cout << brute(s, 2) << endl;
}