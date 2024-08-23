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
bool isSameTree(TreeNode *p, TreeNode *q)
{
  if (p == NULL && q == NULL)
    return true;
  if (p == NULL && q != NULL)
    return false;
  if (p != NULL && q == NULL)
    return false;
  if (p->val != q->val)
  {
    return false;
  }

  if (isSameTree(p->left, q->left))
  {
    return isSameTree(p->right, q->right);
  }
  return false;
}
int main()
{
}