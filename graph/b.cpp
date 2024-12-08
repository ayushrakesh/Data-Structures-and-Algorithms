#include <iostream>
#include <vector>
using namespace std;

void sortPeaksAndValleys(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (i % 2 == 0)
        { // Even index, should be a peak
            if (i > 0 && arr[i] < arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
            }
            if (i < arr.size() - 1 && arr[i] < arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        else
        { // Odd index, should be a valley
            if (i > 0 && arr[i] > arr[i - 1])
            {
                swap(arr[i], arr[i - 1]);
            }
            if (i < arr.size() - 1 && arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int main()
{
    // Hardcoded input array
    vector<int> arr = {5, 3, 1, 2, 3};

    // Print the original array
    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Sort the array into peaks and valleys
    sortPeaksAndValleys(arr);

    // Print the sorted array
    cout << "Array after sorting into peaks and valleys: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}