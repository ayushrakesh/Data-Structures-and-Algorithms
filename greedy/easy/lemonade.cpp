#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool lemonadeChange(vector<int> &bills)
  {
    int n = bills.size();
    int sum = 0;
    int five = 0, ten = 0, fif = 0;

    for (int i = 0; i < n; i++)
    {
      if (bills[i] == 5)
      {
        five++;
      }
      else if (bills[i] == 10)
      {
        ten++;
        if (five >= 1)
        {
          five--;
        }
        else
          return false;
      }
      else
      {
        fif++;
        if (five >= 1 && ten >= 1)
        {
          five--;
          ten--;
        }
        else if (five >= 3)
        {
          five -= 3;
        }
        else
          return false;
      }
    }
    return true;
  }
};