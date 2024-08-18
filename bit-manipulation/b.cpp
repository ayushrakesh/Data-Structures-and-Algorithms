#include <bits/stdc++.h>
using namespace std;
long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
{
  int n = energyDrinkA.size();
  long long maxi = 0;
  int i = 0, j = 0;
  bool b = false;

  while (i < n && j < n)
  {
    if ((energyDrinkA[i] + energyDrinkA[i + 1]) >= energyDrinkB[j + 1])
    {
      b = true;
      maxi = maxi + energyDrinkA[i];
      if (i == (n - 2) && b)
      {
        maxi = maxi + energyDrinkA[n - 1];
        break;
      }
      i++;
      j++;
    }
    else
    {
      if ((j + 1) != (n - 1))
      {
        maxi = maxi + energyDrinkB[j + 1];
      }
      b = false;
      if (j == (n - 2) && !b)
      {
        maxi = maxi + energyDrinkB[n - 1];
        break;
      }
      i++;
      j++;
    }
  }
  return maxi;
}
int main()
{
}