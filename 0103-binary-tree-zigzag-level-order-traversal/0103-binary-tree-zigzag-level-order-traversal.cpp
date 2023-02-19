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
            //cout<<"**"<<endl;
            //cout<<s<<endl;
            vector<int>temp;
            if(level%2==1) {
                while(s--) {
                    TreeNode* t=q.front();
                    q.pop_front();
                  //  cout<<t->val<<endl;
                    if(t->right) {
                        q.push_back(t->right);
                        temp.push_back(t->right->val);
                       // cout<<t->right->val<<endl;
                    }
                    
                    if(t->left) {
                        q.push_back(t->left);
                        temp.push_back(t->left->val);
                        //cout<<t->left->val<<endl;
                    }
                }
            }
            
              else {
                  while(s--) {
                    TreeNode* t=q.back();
                    q.pop_back();
                //    cout<<t->val<<endl;
                    if(t->left) {
                        q.push_front(t->left);
                        temp.push_back(t->left->val);
                       // cout<<t->left->val<<endl;
                    }
                    
                    if(t->right) {
                        q.push_front(t->right);
                        temp.push_back(t->right->val);
                      //  cout<<t->right->val<<endl;
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