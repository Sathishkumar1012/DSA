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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)
            return root;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        vector<int>values;
        while(!q.empty()) {
            int s=q.size()-1;
            vector<int>temp;
            while(s>=0) {
                TreeNode* t=q.front();
                q.pop();
                
                if(level%2==1) {
                    t->val=values[s];
                }
                
                if(t->left) {
                    q.push(t->left);
                    temp.push_back(t->left->val);
                }
                
                if(t->right) {
                    q.push(t->right);
                    temp.push_back(t->right->val);
                }
                s--;
            }
            values=temp;
            level++;
        }
        return root;
    }
};