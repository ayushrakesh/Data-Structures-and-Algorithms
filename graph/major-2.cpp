#include <bits/stdc++.h>
using namespace std;

int main()
{
  int costMatrix[5][4] = {{10, 12, 4, 20}, {2, 7, 14, 15}, {20, 9, 16, 15}, {11, 20, 18, 10}, {35, 15, 10, -1}};

  pair<int, pair<int, int>> sortedValues[12];
  int index = 0;

  for (int row = 0; row < 4; row++)
  {
    for (int col = 0; col < 3; col++)
    {

      sortedValues[index++] = {costMatrix[row][col], {row, col}};
    }
  }

  map<int, string> cityNames;

  cityNames[0] = "kolkata";
  cityNames[1] = "hyderabad";
  cityNames[2] = "mumbai";

  sort(sortedValues, sortedValues + 12);

  int rowVisited[4] = {0};
  int colVisited[3] = {0};

  int totalCost = 0;
  map<int, vector<string>> result;

  for (int i = 0; i < 12; i++)
  {
    int row = sortedValues[i].second.first;
    int col = sortedValues[i].second.second;
    int val = sortedValues[i].first;

    if (rowVisited[row] != 1 && colVisited[col] != 1)
    {
      if (costMatrix[row][3] > costMatrix[4][col])
      {

        colVisited[col] = 1;
        totalCost += costMatrix[row][col] * costMatrix[4][col];
        // cout<<row<<" "<<col<<" "<<val<<" "<<costMatrix[4][col]<<endl;
        costMatrix[row][3] -= costMatrix[4][col];
        costMatrix[4][col] = 0;
        result[row].push_back(cityNames[col]);
      }
      else if (costMatrix[row][3] < costMatrix[4][col])
      {

        rowVisited[row] = 1;
        totalCost += costMatrix[row][col] * costMatrix[row][3];
        // cout<<row<<" "<<col<<" "<<val<<" "<<costMatrix[row][3]<<endl;
        costMatrix[4][col] -= costMatrix[row][3];
        costMatrix[row][3] = 0;
        result[row].push_back(cityNames[col]);
      }
      else
      {

        colVisited[col] = 1;
        rowVisited[row] = 1;
        totalCost += costMatrix[row][col] * costMatrix[row][3];
        // cout<<row<<" "<<col<<" "<<val<<" "<<costMatrix[row][3]<<endl;
        costMatrix[row][3] = 0;
        costMatrix[4][col] = 0;
        result[row].push_back(cityNames[col]);
      }
    }
  }
  cout << totalCost << endl;

  for (auto it : result)
  {
    cout << it.first + 1 << " : ";
    for (auto city : it.second)
    {
      cout << city << ", ";
    }
    cout << endl;
  }

  // for(auto &x : sortedValues){
  //     cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
  // }

  return 0;
}