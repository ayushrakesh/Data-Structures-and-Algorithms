#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long test = 0;
  cin >> test;

  for (long long h = 0; h < test; h++)
  {
    long long n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<char> cv;

    for (long long i = 0; i < q; i++)
    {
      char c;
      cin >> c;
      s = s + c;
      // cv.push_back(c);
    }

    long long i = 0, j = 0;
    long long maxi = 0;
    long long curr = 0;

    for (; j < s.length();)
    {
      if (s[i] == s[j])
      {
        curr++;
        j++;
      }
      else
      {
        // i = j;
        curr = 1;
        j++;
        i = j;
      }

      maxi = max(curr, maxi);

      if (j >= n - 1)
      {
        cout << maxi << endl;
      }
    }

    // cout << maxi << endl;

    // for (long long k = 0; k < q; k++)
    // {
    //   s = s + cv[k];

    //   if (s[i] == s[j])
    //   {
    //     curr++;
    //     j++;
    //   }
    //   else
    //   {
    //     i = j;
    //     curr = 1;
    //     j++;
    //   }
    //   maxi = max(curr, maxi);

    //   cout << maxi << endl;
    // }
  }
}