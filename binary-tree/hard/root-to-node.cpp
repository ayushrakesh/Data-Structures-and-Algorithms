#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    left = right = nullptr;
  }
};

void solve(vector<vector<int>> &res, Node *root, vector<int> &path)
{
  if (root == NULL)
    return;

  path.push_back(root->data);

  if (root->left == NULL && root->right == NULL)
  {
    res.push_back(path);
    return;
  }

  if (root->left != NULL)
  {
    solve(res, root->left, path);
    path.pop_back();
  }

  if (root->right != NULL)
  {
    solve(res, root->right, path);
    path.pop_back();
  }
}
vector<vector<int>> Paths(Node *root)
{
  // code here
  vector<vector<int>> res;
  vector<int> path;
  solve(res, root, path);
  return res;
}