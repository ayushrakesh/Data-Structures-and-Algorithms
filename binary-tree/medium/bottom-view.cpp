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
void solve(TreeNode *root, vector<int> &res)
{
  if (root == NULL)
    return;
  queue<pair<TreeNode *, int>> que;
  map<int, int> mp;

  que.push(make_pair(root, 0));

  while (!que.empty())
  {
    pair<TreeNode *, int> p = que.front();
    que.pop();

    int vl = p.second;
    TreeNode *node = p.first;

    mp[vl] = node->val;
    if (node->left != NULL)
    {
      que.push(make_pair(node->left, vl - 1));
    }
    if (node->right != NULL)
    {
      que.push(make_pair(node->right, vl + 1));
    }
  }

  for (auto it : mp)
  {
    res.push_back(it.second);
  }
}
vector<int> topView(Node *root)
{
  vector<int> res;
  solve(root, res);
  return res;
  // Your code here
}