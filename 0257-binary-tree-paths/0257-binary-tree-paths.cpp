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
    void Paths(TreeNode* root, vector<string>&ans, string s ){
        if(s.length() != 0){
            s+="->";
        }
        s+=to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
        if(root->left){
            Paths(root->left, ans, s);
        }
        if(root->right){
            Paths(root->right, ans, s);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        string s;
        Paths(root, paths, s);
        return paths;
    }
};