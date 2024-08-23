#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int d)
  {
    this->val = d;
    left = right = nullptr;
  }
};
void solve(TreeNode *root, vector<vector<int>> &res)
{
  queue<TreeNode *> que;
  if (root == NULL)
    return;
  que.push(root);
  bool b = false;

  while (!que.empty())
  {
    int size = que.size();
    vector<int> level(size, 0);

    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = que.front();
      que.pop();

      if (curr->left != NULL)
      {
        que.push(curr->left);
      }
      if (curr->right != NULL)
      {
        que.push(curr->right);
      }

      if (b == 0)
      {
        level[i] = curr->val;
      }
      else
      {
        level[size - i - 1] = curr->val;
      }
    }
    b = !b;
    res.push_back(level);
  }
}