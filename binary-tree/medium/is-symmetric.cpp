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
bool bfs(TreeNode *root)
{
  if (root = NULL)
    return true;

  deque<pair<TreeNode *, int>> d;
  d.push_back({root, 0});

  while (!d.empty())
  {
    int size = d.size();
    vector<int> level;
    for (int i = 0; i < size; i++)
    {
      TreeNode *node = d.front().first;
      int ind = d.front().second;
      d.pop_front();

      if (node->left)
      {
        d.push_back({node->left, 2 * ind + 1});
        level.push_back(node->left->val);
      }
      else
      {
        level.push_back(101);
      }
      if (node->right)
      {
        d.push_back({node->right, 2 * ind + 2});
        level.push_back(node->right->val);
      }
      else
      {
        level.push_back(101);
      }
    }
    int n = level.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
      if (level[i] != level[j])
        return false;
      i++;
      j--;
    }
  }
  return true;
}
bool isSymmetric(TreeNode *root)
{
}