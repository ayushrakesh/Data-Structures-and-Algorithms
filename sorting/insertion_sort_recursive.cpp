#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n, int i)
{
  if (i == n)
    return;

  for (int j = i; j >= 1; j--)
  {
    if (arr[j] < arr[j - 1])
    {
      swap(arr[j], arr[j - 1]);
    }
  }

  insertionSort(arr, n, i + 1);
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

  insertionSort(arr, n, 0);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}