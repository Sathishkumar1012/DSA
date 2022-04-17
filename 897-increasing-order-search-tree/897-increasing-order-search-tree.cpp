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
    void solve(TreeNode* root,TreeNode* &temp) {
        if(!root)
            return;
        
        solve(root->left,temp);
        int x=root->val;
        temp->right=new TreeNode(x);
        temp=temp->right;
        solve(root->right,temp);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* t=new TreeNode();
        TreeNode* temp=t;
        solve(root,t);
        return temp->right;
    }
};