#include <bits/stdc++.h>
using namespace std;
int solve(Node *root)
{
  if (root == NULL)
    return 0;

  int left = 0, right = 0;

  if (root->left != NULL)
  {
    left = solve(root->left);
  }
  if (root->right != NULL)
  {
    right = solve(root->right);
  }

  if (left == 0 && right == 0)
    return root->data;
  if ((left + right) == root->data)
    return root->data;
  return 0;
}
// Function to check whether all nodes of a tree have the value
// equal to the sum of their child nodes.
int isSumProperty(Node *root)
{
  int res = solve(root);
  if (res)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}