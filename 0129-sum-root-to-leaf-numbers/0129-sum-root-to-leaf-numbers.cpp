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
    int helper(int val,TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return val*10+root->val;
        return helper(val*10+root->val,root->left)+helper(val*10+root->val,root->right);
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(0,root);
    }
};