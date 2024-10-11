#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

map<int, int> allocateServers(vector<vector<int>> &v, vector<int> &caps, vector<int> &reqs)
{
  map<int, int> result;

  while (!v.empty())
  {
    int mini = INT_MAX;
    int minrow = -1, mincol = -1;

    for (int i = 0; i < v.size(); ++i)
    {
      for (int j = 0; j < v[i].size(); ++j)
      {
        if (v[i][j] < mini)
        {
          mini = v[i][j];
          minrow = i;
          mincol = j;
        }
      }
    }

    int serCap = caps[minrow];
    int cityReq = reqs[mincol];
    int alloc = min(serCap, cityReq);
    result[mini] = alloc;

    caps[minrow] -= alloc;
    reqs[mincol] -= alloc;

    if (caps[minrow] == 0)
    {
      v.erase(v.begin() + minrow);
      caps.erase(caps.begin() + minrow);
    }
    else if (reqs[mincol] == 0)
    {
      for (int i = 0; i < v.size(); ++i)
      {
        v[i].erase(v[i].begin() + mincol);
      }
      reqs.erase(reqs.begin() + mincol);
    }
    else
    {
      v[minrow][mincol] = INT_MAX;
    }

    v.erase(
        remove_if(v.begin(), v.end(), [](vector<int> &row)
                  { return row.empty(); }),
        v.end());
  }

  return result;
}

void runTest(int n)
{
  // Initialize random number generator
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(1, 1000);

  // Create nxn matrix with random values
  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      v[i][j] = dist(gen);
    }
  }

  // Create caps and reqs such that sum of all caps = sum of all reqs
  vector<int> caps(n), reqs(n);
  int total = 0;

  for (int i = 0; i < n; ++i)
  {
    caps[i] = dist(gen);
    reqs[i] = dist(gen);
    total += caps[i]; // Add to total
  }

  int sum_caps = accumulate(caps.begin(), caps.end(), 0);
  int sum_reqs = accumulate(reqs.begin(), reqs.end(), 0);

  // Adjust reqs so that sum_reqs equals sum_caps
  if (sum_caps != sum_reqs)
  {
    reqs[n - 1] += (sum_caps - sum_reqs);
  }

  // Measure the time taken for the allocation
  auto start = high_resolution_clock::now();
  map<int, int> result = allocateServers(v, caps, reqs);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(end - start);

  cout << "Matrix size: " << n << "x" << n << ", Time taken: " << duration.count() << " ms\n";
}

int main()
{
  vector<int> matrix_sizes = {1000, 2000, 3000}; // Add as many as you want up to 100 million

  for (int n : matrix_sizes)
  {
    runTest(n);
  }

  return 0;
}
