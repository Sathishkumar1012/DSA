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
    int res=0;
    void helper(TreeNode* root,int temp) {
        if(!root)
            return;
        if(!root->left && !root->right) {
            res+=(temp*10+root->val);
            return;
        }
        helper(root->left,temp*10+root->val);
        helper(root->right,temp*10+root->val);
        return;
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        helper(root,0);
        return res;
    }
};