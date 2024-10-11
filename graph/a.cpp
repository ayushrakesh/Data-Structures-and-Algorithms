#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  const int n = 15;
  pair<int, int> users[n];
  pair<int, int> sorted[n];

  srand(static_cast<unsigned>(time(0)));

  for (int i = 0; i < n; i++)
  {
    users[i].first = i + 1;
    users[i].second = rand() % 20 + 1;
    sorted[i] = {-1, -1};
  }

  int start = 0, end = n - 1;
  int remaining = n;

  while (remaining > 0)
  {
    pair<int, int> min_user = users[0];
    int index = 0;

    for (int i = 1; i < remaining; i++)
    {
      if (min(min_user.first, min_user.second) > min(users[i].first, users[i].second))
      {
        min_user = users[i];
        index = i;
      }
    }

    if (min_user.first > min_user.second)
    {
      sorted[end] = min_user;
      end--;
    }
    else
    {
      sorted[start] = min_user;
      start++;
    }

    for (int i = index; i < remaining - 1; i++)
    {
      users[i] = users[i + 1];
    }
    remaining--;
  }

  for (int i = 0; i < n; i++)
  {
    cout << "User " << i + 1 << ": (Arrival: " << sorted[i].first << ", Service: " << sorted[i].second << ") " << endl;
  }

  return 0;
}
