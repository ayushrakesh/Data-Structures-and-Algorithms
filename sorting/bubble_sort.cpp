#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
  for (int i = n - 2; i >= 0; i--)
  {
    bool didSwap = false;
    for (int j = 0; j <= i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j + 1], arr[j]);
        didSwap = true;
      }
    }

    if (!didSwap)
    {
      break;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  bubbleSort(arr, n);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}