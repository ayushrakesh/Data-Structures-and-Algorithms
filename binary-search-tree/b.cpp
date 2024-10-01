
#include <bits/stdc++.h>
using namespace std;
int timeToMinutes(const string &time)
{
  int hours = stoi(time.substr(0, 2));   // Extract hours
  int minutes = stoi(time.substr(3, 2)); // Extract minutes
  return hours * 60 + minutes;
}
int findMinDifference(vector<string> &timePoints)
{
  vector<int> minutes;

  for (int i = 0; i < timePoints.size(); i++)
  {
    minutes.push_back(timeToMinutes(timePoints[i]));
  }
  minutes.push_back(1440);
  sort(minutes.begin(), minutes.end());
  int ans = INT_MAX;
  for (int i = 1; i < minutes.size(); i++)
  {
    ans = min(ans, minutes[i] - minutes[i - 1]);
  }
  return ans;
}
int main()
{
  vector<string> v = {"00:23", "14:28", "00:00", "14:28", "14:29", "00:59"};
  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}