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
    map<string,int>m;
    string helper(TreeNode* root,vector<TreeNode*> &res) {
        if(!root)
            return "N";
        string left=helper(root->left,res);
        string right=helper(root->right,res);
        string t=to_string(root->val) + "*" + left + "*" + right;
        
        m[t]++;
        
        if(m[t]==2)
            res.push_back(root);
        
        return t;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        helper(root,res);
        return res;
    }
};