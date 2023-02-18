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
    bool check(TreeNode* root,int temp) {
        if(!root)
            return true;
        if(root->val!=temp)
            return false;
        return check(root->left,temp) && check(root->right,temp);
    }
    
    bool isUnivalTree(TreeNode* root) {
        int temp=root->val;
        return check(root,temp);
    }
};