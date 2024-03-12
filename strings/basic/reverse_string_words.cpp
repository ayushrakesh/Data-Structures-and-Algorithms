#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;

  string t;

  int rightInd = s.length() - 1;
  int leftInd = s.length() - 1;

  while (leftInd >= 0 || rightInd >= 0)
  {

    while (s[rightInd] == ' ')
    {
      rightInd--;
      /* code */
    }
    while (s[leftInd] == ' ')
    {
      leftInd--;
      /* code */
    }

    int temp2 = rightInd;

    while (s[leftInd] != ' ')
    {
      leftInd--;
      /* code */
    }
    int temp1 = leftInd;
    temp1++;

    while (temp1 <= rightInd)
    {
      t.append(to_string(s[temp1]));
      temp1++;
      /* code */
    }

    t.append(" ");

    rightInd = leftInd;
    /* code */
  }

  cout << t << endl;
}