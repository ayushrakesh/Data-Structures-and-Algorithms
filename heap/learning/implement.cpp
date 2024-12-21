#include <bits/stdc++.h>
using namespace std;

class Heap
{
  int size;
  int capacity;
  int *heap;

public:
  Heap(int c)
  {
    this->capacity = c;
    this->size = 0;
    this->heap = new int[c];
  }

  void insert(int val)
  {
    if (size == capacity)
    {
      return;
    }
    size++;
    heap[size] = val;

    int index = size;
    while (index > 1)
    {
      int parentIndex = index / 2;
      if (heap[parentIndex] < heap[index])
      {
        swap(heap[parentIndex], heap[index]);
        index = parentIndex;
      }
      else
        break;
    }
  }

  int deleteHeap()
  {
    int ans = heap[1];
    heap[1] = heap[size];
    size--;

    int index = 1;
    while (index < size)
    {
      int left = index * 2;
      int right = index * 2 + 1;

      int largest = index;
      if (left <= size && heap[largest] < heap[left])
      {
        largest = left;
      }

      if (right <= size && heap[largest] < heap[right])
      {
        largest = right;
      }
      if (index == largest)
        break;
      swap(heap[largest], heap[index]);
      index = largest;
    }
    return ans;
  }

  void print()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};
void heapify(int n, int index, vector<int> &arr)
{
  if (index == n)
    return;
  int left = 2 * index;
  int right = 2 * index + 1;
  int largest = index;

  if (left <= n && arr[left] > arr[largest])
    largest = left;
  if (right <= n && arr[right] > arr[largest])
    largest = right;

  if (index != largest)
  {
    swap(arr[largest], arr[index]);
    heapify(n, largest, arr);
  }
}

void heapSort(int n, vector<int> &arr)
{
  while (n > 1)
  {
    swap(arr[1], arr[n]);
    n--;
    heapify(n, 1, arr);
  }
}
void buildHeap(vector<int> &v, int n)
{
  for (int index = n / 2; index >= 1; index--)
  {
    heapify(n, index, v);
  }
}
void print(vector<int> v, int n)
{
  for (int i = 1; i <= n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
int main()
{
  Heap h(10);
  h.insert(5);
  h.insert(2);
  h.insert(10);
  h.insert(3);
  h.insert(9);
  h.insert(11);

  h.print();

  h.deleteHeap();
  h.deleteHeap();
  h.deleteHeap();
  h.print();

  vector<int> v = {-1, 90, 5, 67, 34, 10, 91};
  int n = v.size() - 1;

  buildHeap(v, n);
  print(v, n);

  heapSort(n, v);
  print(v, n);
}