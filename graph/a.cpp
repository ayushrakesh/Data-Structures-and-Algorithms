#include <iostream>
#include <utility> // For using std::pair
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()
using namespace std;

int main()
{
  const int size = 15;      // Size of the array for 15 users
  pair<int, int> vec[size]; // Array to store pairs of (arrival time, service time)
  pair<int, int> ans[size]; // Output array

  // Seed the random number generator
  srand(static_cast<unsigned>(time(0)));

  // Fill vec with random service times and arrival times (keeping arrival times fixed for simplicity)
  for (int i = 0; i < size; i++)
  {
    vec[i].first = i + 1;            // Simulate arrival time as increasing sequence (1, 2, ..., 15)
    vec[i].second = rand() % 20 + 1; // Random service time between 1 and 20
    ans[i] = {-1, -1};               // Initialize ans with (-1, -1)
  }

  int b = 0, l = size - 1;
  int vecSize = size; // To track the remaining elements in the input array

  while (vecSize > 0)
  {
    pair<int, int> p = vec[0];
    int r = 0;

    for (int i = 1; i < vecSize; i++)
    {
      if (min(p.first, p.second) > min(vec[i].first, vec[i].second))
      {
        p = vec[i];
        r = i;
      }
    }

    if (p.first > p.second)
    {
      ans[l] = p;
      l--;
    }
    else
    {
      ans[b] = p;
      b++;
    }

    // Shift elements in vec to remove vec[r]
    for (int i = r; i < vecSize - 1; i++)
    {
      vec[i] = vec[i + 1]; // Move elements left to "erase" vec[r]
    }
    vecSize--; // Reduce the size after "erasing"
  }

  // Output the final sorted array
  for (int i = 0; i < size; i++)
  {
    cout << "User " << i + 1 << ": (Arrival: " << ans[i].first << ", Service: " << ans[i].second << ") " << endl;
  }

  return 0;
}
