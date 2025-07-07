/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int num = -1;
    int diff = INT_MAX;
    void f(TreeNode* root){
        if(!root) return ;
        f(root->left);
       if(num != -1) diff = min(diff,abs(root->val - num));
        num = root->val;
        f(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        f(root);
        return diff;
    }
};