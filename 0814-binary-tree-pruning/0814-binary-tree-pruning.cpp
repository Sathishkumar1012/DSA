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
    int check(TreeNode* root) {
        if(!root)
            return 0;
        int left=check(root->left);
        int right=check(root->right);
        root->left=left==0?NULL:root->left;
        root->right=right==0?NULL:root->right;
        return left+right+root->val;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        if(check(root)==0)
            return NULL;
        return root;
    }
};