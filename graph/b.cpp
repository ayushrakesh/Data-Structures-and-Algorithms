#include <iostream>
#include <utility> // For using std::pair
using namespace std;

int main()
{
  const int size = 6; // Fixed size for the array (6 users)
  pair<int, int> vec[size] = {{6, 5}, {12, 7}, {14, 10}, {7, 8}, {10, 14}, {11, 4}};
  pair<int, int> ans[size]; // Output array

  // Initialize the `ans` array with (-1, -1)
  for (int i = 0; i < size; i++)
  {
    ans[i] = {-1, -1};
  }

  int b = 0, l = size - 1;
  int vecSize = size; // Track the remaining elements in the input array

  while (vecSize > 0)
  {
    pair<int, int> p = vec[0];
    int r = 0;

    // Find the pair with the smallest min(first, second) value
    for (int i = 1; i < vecSize; i++)
    {
      if (min(p.first, p.second) > min(vec[i].first, vec[i].second))
      {
        p = vec[i];
        r = i;
      }
    }

    // Place the selected pair in either the left or right part of the `ans` array
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

    // Remove the selected element by shifting the array left
    for (int i = r; i < vecSize - 1; i++)
    {
      vec[i] = vec[i + 1]; // Shift elements left to "erase" vec[r]
    }
    vecSize--; // Reduce the size after "erasing"
  }

  // Output the final sorted array
  for (int i = 0; i < size; i++)
  {
    cout << "(" << ans[i].first << ", " << ans[i].second << ") ";
  }
  cout << endl;

  return 0;
}
