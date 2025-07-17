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
    int bfs(TreeNode*root){
        int res=0;
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode*node=q.front();
                q.pop();

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            res++;
        }
        return res;
    }
    int maxDepth(TreeNode* root) {
        return bfs(root);
    }
};