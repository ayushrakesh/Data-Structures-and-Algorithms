#include <bits/stdc++.h>
using namespace std;
bool checkTwoChessboards(string coordinate1, string coordinate2)
{
  if ((int)coordinate1[0] % 2 == 1 && (coordinate1[1] == '1' || coordinate1[1] == '3' || coordinate1[1] == '5' || coordinate1[1] == '7'))
  {
    if ((int)coordinate2[0] % 2 == 1 && (coordinate2[1] == '1' || coordinate2[1] == '3' || coordinate2[1] == '5' || coordinate2[1] == '7'))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  else
  {
    if ((int)coordinate2[0] % 2 == 0 && (coordinate2[1] == '2' || coordinate2[1] == '4' || coordinate2[1] == '6' || coordinate2[1] == '8'))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}