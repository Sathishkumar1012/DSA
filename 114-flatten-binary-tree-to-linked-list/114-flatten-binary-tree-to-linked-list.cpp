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
    void flatten(TreeNode* root) {
        res(root,NULL);
    }
    
    TreeNode* res(TreeNode* root,TreeNode* pre) {
        if(root==NULL)
            return pre;
        
        pre=res(root->right,pre);
        pre=res(root->left,pre);
        root->right=pre;
        root->left=NULL;
        pre=root;
        return pre;
    }
};