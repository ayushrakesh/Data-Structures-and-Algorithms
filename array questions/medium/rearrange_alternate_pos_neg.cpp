#include <bits/stdc++.h>
using namespace std;

// Optimal solution for only equal positives and negatives
vector<int> rearrangeAltPosNeg_1(vector<int> &v)
{
  int n = v.size();
  vector<int> res;

  int posIndex = 0, negIndex = 1;

  for (int i = 0; i < n; i++)
  {
    if (v[i] < 0)
    {
      res[negIndex] = v[i];
      negIndex += 2;
    }
    else
    {
      res[posIndex] = v[i];
      posIndex += 2;
    }
  }

  return res;
}

// Optimal solution for unequal positives and negatives
void rearrangeAltPosNeg_2(vector<int> &v)
{
  vector<int> res;
  vector<int> pos, neg;

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] < 0)
    {
      neg.push_back(v[i]);
    }
    else
    {
      pos.push_back(v[i]);
    }
  }

  int n = v.size();

  if (pos.size() < neg.size())
  {
    for (int i = 0; i < pos.size(); i++)
    {
      v[2 * i] = pos[i];
      v[2 * i + 1] = neg[i];
    }

    int index = 2 * pos.size();

    for (int i = pos.size(); i < neg.size(); i++)
    {
      v[index] = neg[i];
      index++;
    }
  }
  else
  {
    for (int i = 0; i < neg.size(); i++)
    {
      v[2 * i] = pos[i];
      v[2 * i + 1] = neg[i];
    }

    int index = 2 * neg.size();

    for (int i = neg.size(); i < pos.size(); i++)
    {
      v[index] = pos[i];
      index++;
    }
  }
}
int main()
{
  int n;
  cin >> n;
  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v.push_back(a);
  }

  // vector<int> res = rearrangeAltPosNeg_1(v);

  rearrangeAltPosNeg_2(v);

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
}