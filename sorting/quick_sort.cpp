#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{

  int i = low;
  int j = high;
  int pivot = arr[low];

  while (i < j)
  {
    /* code */
    while (arr[i] <= pivot && i <= high - 1)
    {
      i++;
    }
    while (arr[j] > pivot && j >= low + 1)
    {
      j--;
    }

    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[low], arr[j]);

  return j;
}

void quickSort(int arr[], int low, int high)
{

  if (low < high)
  {
    int partitionIndex = partition(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
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

  quickSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}