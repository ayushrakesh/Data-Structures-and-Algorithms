int n = v.size();
  int m = v[0].size();

  int low = 0, high = m - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    int rowInd = maxElement(v, mid);

    int left = mid >= 1 ? v[rowInd][mid - 1] : -1;
    int right = mid < m - 1 ? v[rowInd][mid + 1] : -1;

    if (v[rowInd][mid] > left && v[rowInd][mid] > right)
      return {rowInd, mid};
    else if (v[rowInd][mid] < left)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return {-1, -1};