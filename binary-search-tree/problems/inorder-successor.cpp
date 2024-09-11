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
  Node *solve(Node *root, Node *x, Node *prev)
  {
    if (!root)
      return root;

    if (root->data == x->data)
    {
      if (!root->right)
        return prev;
      else
      {
        Node *temp = root->right;
        while (temp->left)
        {
          temp = temp->left;
        }
        return temp;
      }
    }
    Node *t = solve(root->left, x, root);
    if (t)
      return t;
    return solve(root->right, x, prev);
  }
  // returns the inorder successor of the Node x in BST (rooted at 'root')
  Node *inOrderSuccessor(Node *root, Node *x)
  {
    // Your code here
    Node *t = NULL;
    Node *ans = solve(root, x, t);
    if (ans)
      return ans;
    return new Node(-1);
    // return solve(root,x,t);
  }
};