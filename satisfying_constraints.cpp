#include <bits/stdc++.h>
using namespace std;
bool kel(vector<long long> d, long long a)
{
  int count = 0;

  for (int i = 0; i < d.size(); i++)
  {
    /* code */
    if (a != d[i])
    {
      count++;
    }
  }
  if (count == d.size())
  {
    return true;
  }
  else
  {
    return false;
  }
}
int binarySearch(vector<long long> arr, int l, int r, long long x)
{
  if (r >= l)
  {
    long long mid = l + (r - l) / 2;

    // If the element is present at the middle
    // itself
    if (arr[mid] == x)
      return mid;

    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);

    // Else the element can only be present
    // in right subarray
    return binarySearch(arr, mid + 1, r, x);
  }

  // We reach here when element is not
  // present in array
  return -1;
}
int main()
{
  int q = 0;
  cin >> q;

  for (int o = 0; o < q; o++)
  {
    int n;
    cin >> n;

    // vector<pair<int, int>> v;
    vector<long long int> w;
    vector<long long int> y;
    vector<long long int> z;

    for (int i = 0; i < n; i++)
    {
      int a;
      long long x;
      cin >> a;
      cin >> x;

      if (a == 1)
      {
        w.push_back(x);
      }
      else if (a == 2)
      {
        y.push_back(x);
      }
      else
      {
        z.push_back(x);
      }
    }
    long long mini = *max_element(w.begin(), w.end());
    long long maxi = *min_element(y.begin(), y.end());

    // bool gett = false;
    long long count2 = 0;
    for (long long i = mini; i <= maxi; i++)
    {
      /* code */
      // vector<long long>::iterator it;
      // using the find() function and storing the result in iterator ‘it’
      // it = find(z.begin(), z.end(), i);
      // checking the condition based on the ‘it’ result whether the element is present or not

      if (binarySearch(z, 0, 0, i) == -1)
      {
        count2++;
      }
    }
    cout << count2 << endl;
  }
}
