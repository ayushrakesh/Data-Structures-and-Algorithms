#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
  int n = cardPoints.size();
  int maxscore = 0;
  int leftsum = 0, rightsum = 0;
  for (int i = 0; i < k; i++)
  {
    leftsum += cardPoints[i];
  }
  maxscore = leftsum;
  int total = leftsum;

  int left = k - 1;
  int right = n - 1;

  while (left >= 0)
  {
    leftsum -= cardPoints[left];
    left--;

    rightsum += cardPoints[right];
    right--;

    total = leftsum + rightsum;
    maxscore = max(maxscore, total);
  }
  return maxscore;
}
int main()
{
}