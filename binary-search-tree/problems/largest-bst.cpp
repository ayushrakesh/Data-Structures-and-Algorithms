#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
public:
  typedef pair<int, pair<int, int>> p;
  p solve(Node *root)
  {
    if (!root)
      return {0, {INT_MIN, INT_MAX}};
    if (!root->left && !root->right)
      return {1, {root->data, root->data}};

    p left = solve(root->left);
    p right = solve(root->right);

    if (root->data > left.second.first && root->data < right.second.second)
    {
      return {left.first + right.first + 1, {max(root->data, max(left.second.first, right.second.first)), min(root->data, min(left.second.second, right.second.second))}};
    }
    return {max(left.first, right.first), {INT_MAX, INT_MIN}};
  }
  /*You are required to complete this method */
  // Return the size of the largest sub-tree which is also a BST
  int largestBst(Node *root)
  {
    return solve(root).first;
    // Your code here
  }
};