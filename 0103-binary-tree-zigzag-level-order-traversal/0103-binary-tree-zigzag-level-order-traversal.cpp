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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        
         if(!root)
            return result;
        
        deque<TreeNode*>q;
        q.push_back(root);
        result.push_back({root->val});
        int level=1;
        
        while(!q.empty()) {
            int s=q.size();
            vector<int>temp;
            while(s--) {
                if(level%2==1) {
                    TreeNode* t=q.front();
                    q.pop_front();
                    if(t->right) {
                        q.push_back(t->right);
                        temp.push_back(t->right->val);
                    }
                    
                    if(t->left) {
                        q.push_back(t->left);
                        temp.push_back(t->left->val);
                    }
                }
                
                else {
                    TreeNode* t=q.back();
                    q.pop_back();
                    if(t->left) {
                        q.push_front(t->left);
                        temp.push_back(t->left->val);
                    }
                    
                    if(t->right) {
                        q.push_front(t->right);
                        temp.push_back(t->right->val);
                    }
                }
            }
            level++;
            if(temp.size()>0)
            result.push_back(temp);
        }
        
        return result;
    }
};