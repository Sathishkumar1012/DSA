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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int flag=0;
        while(!q.empty()) {
            int n=q.size();
            int i=0;
            while(i<n) {
                TreeNode* t=q.front();
                q.pop();
                if(flag) {
                    if(t->left || t->right)
                        return false;
                }
                
                if(!t->left && t->right)
                    return false;
                else if(t->left && !t->right) {
                    flag=1;
                    q.push(t->left);
                }
                
                else if(!t->left && !t->right)
                    flag=1;
                
                else {
                    if(t->left)
                        q.push(t->left);
                    if(t->right)
                        q.push(t->right);
                }
                
                i++;
            }
        }
        return true;
    }
};