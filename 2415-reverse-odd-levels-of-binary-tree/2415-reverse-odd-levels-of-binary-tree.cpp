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
    stack<int>s;
    void check1(TreeNode* root,int level) {
        if(!root)
            return;
        check1(root->left,level+1);
        check1(root->right,level+1);
        
        if(level%2==1) {
            //cout<<"..."<<root->val<<endl;
            s.push(root->val);
        }
       // return root;
    }
    
    
    void check2(TreeNode* root,int level) {
        if(!root)
            return;
        
        if(level%2==1) {
            if(!s.empty())
              //  cout<<"---"<<s.top()<<endl;
            root->val=s.top();
            s.pop();
        }
        
        check2(root->left,level+1);
        check2(root->right,level+1);
        
      //  return root;
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        stack<int>s;
        check1(root,0);
       // cout<<s.size()<<endl;
        check2(root,0);
        return root;
    }
};