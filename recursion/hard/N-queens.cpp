#include <bits/stdc++.h>
using namespace std;
bool canFill(int row, int col, vector<string> &board, int n)
{
  int r = row;
  int c = col;

  while (col >= 0)
  {
    if (board[row][col] == 'Q')
    {
      return false;
    }
    col--;
  }

  row = r;
  col = c;

  while (row >= 0 && col >= 0)
  {
    /* code */
    if (board[row][col] == 'Q')
    {
      return false;
    }
    row--;
    col--;
  }

  row = r;
  col = c;

  while (col >= 0 && row < n)
  {
    if (board[row][col] == 'Q')
    {
      return false;
    }
    col--;
    row++;
  }

  return true;
}
void solve(int col, int n, vector<string> &board, vector<vector<string>> &res, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
  if (col == n)
  {
    res.push_back(board);
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (leftRow[i] == 0 && lowerDiagonal[i + col] == 0 && upperDiagonal[n - 1 + col - i] == 0)
    {
      board[i][col] = 'Q';

      leftRow[i] = 1;
      lowerDiagonal[i + col] = 1;
      upperDiagonal[n - 1 + col - i] = 1;

      solve(col + 1, n, board, res, leftRow, upperDiagonal, lowerDiagonal);

      board[i][col] = '.';

      leftRow[i] = 0;
      lowerDiagonal[i + col] = 0;
      upperDiagonal[n - 1 + col - i] = 0;
    }
  }
}
vector<vector<string>> solveNQueens(int n)
{
  vector<string> board(n);

  string s(n, '.');

  for (int i = 0; i < n; i++)
  {
    board[i] = s;
  }
  vector<vector<string>> res;

  solve(0, n, board, res);

  return res;
}

vector<vector<string>> solveNQueensOpt(int n)
{
  vector<string> board(n);

  string s(n, '.');

  for (int i = 0; i < n; i++)
  {
    board[i] = s;
  }
  vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
  vector<vector<string>> res;

  solve(0, n, board, res, leftRow, upperDiagonal, lowerDiagonal);

  return res;
}

int main()
{
  int n;
  cin >> n;

  vector<vector<string>> res = solveNQueensOpt(n);

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[0].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
}