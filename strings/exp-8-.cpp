#include <bits/stdc++.h>
using namespace std;
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

int main()
{
  vector<vector<int>> v = {{10, 2, 20, 11}, {12, 7, 9, 20}, {4, 14, 16, 18}};
  vector<int> caps = {25, 25, 30};
  vector<int> reqs = {10, 25, 25, 20};

  map<int, int> result = allocateServers(v, caps, reqs);

  for (auto it = result.begin(); it != result.end();)
  {
    if (it->second == 0)
    {
      it = result.erase(it);
    }
    else
    {
      ++it;
    }
  }

  for (const auto &entry : result)
  {
    cout << "Distance: " << entry.first << " Allocation: " << entry.second << endl;
  }

  int cost = 0;
  for (auto it : result)
  {
    cost += it.first * it.second;
  }
  cout << "Total cost: " << cost << endl;

  return 0;
}
