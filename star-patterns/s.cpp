#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int N;
    cin >> N;

    vector<vector<int>> triangle(N);

    // Input the triangle
    for (int i = 0; i < N; ++i)
    {
      triangle[i] = vector<int>(i + 1);
      for (int j = 0; j <= i; ++j)
      {
        cin >> triangle[i][j];
      }
    }

    // Dynamic Programming array
    vector<int> dp = triangle[N - 1];

    // Bottom-up calculation
    for (int i = N - 2; i >= 0; --i)
    {
      for (int j = 0; j <= i; ++j)
      {
        dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
      }
    }

    // The result is in dp[0]
    cout << dp[0] << endl;
  }

  return 0;
}