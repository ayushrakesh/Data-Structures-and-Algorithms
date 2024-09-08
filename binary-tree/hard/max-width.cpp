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
void bfs(TreeNode *root, vector<vector<int>> &res)
{
  queue<TreeNode *> que;
  if (root == NULL)
    return;
  que.push(root);

  while (!que.empty())
  {
    int cnt = 0;
    vector<int> level;
    int size = que.size();
    bool b = false;
    for (int i = 0; i < size; i++)
    {
      TreeNode *curr = que.front();
      que.pop();

      if (curr != NULL && !b)
      {
        b = true;
      }
      if (b)
      {
        cnt++;
      }
      if (curr->left != NULL)
      {
        que.push(curr->left);
      }
      if (curr->right != NULL)
      {
        que.push(curr->right);
      }
      level.push_back(curr->val);
    }
    res.push_back(level);
  }
}
int widthOfBinaryTree(TreeNode *root)
{
}