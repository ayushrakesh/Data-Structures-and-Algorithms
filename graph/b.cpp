#include <iostream>
#include <utility>
using namespace std;

int main()
{
  const int n = 6;
  pair<int, int> users[n] = {{6, 5}, {12, 7}, {14, 10}, {7, 8}, {10, 14}, {11, 4}};
  pair<int, int> result[n];

  for (int i = 0; i < n; i++)
  {
    result[i] = {-1, -1};
  }

  int left = 0, right = n - 1;
  int remaining = n;

  while (remaining > 0)
  {
    pair<int, int> min_pair = users[0];
    int index = 0;

    for (int i = 1; i < remaining; i++)
    {
      if (min(min_pair.first, min_pair.second) > min(users[i].first, users[i].second))
      {
        min_pair = users[i];
        index = i;
      }
    }

    if (min_pair.first > min_pair.second)
    {
      result[right] = min_pair;
      right--;
    }
    else
    {
      result[left] = min_pair;
      left++;
    }

    for (int i = index; i < remaining - 1; i++)
    {
      users[i] = users[i + 1];
    }
    remaining--;
  }

  for (int i = 0; i < n; i++)
  {
    cout << "(" << result[i].first << ", " << result[i].second << ") ";
  }
  cout << endl;

  return 0;
}
