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
    unordered_map<int,int>m;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int i,int j) {
        if(i>j)
            return NULL;
        int temp=postorder.back();
        TreeNode* t=new TreeNode(temp);
        postorder.pop_back();
        int pivot=m[temp];
        t->right=helper(inorder,postorder,pivot+1,j);
        t->left=helper(inorder,postorder,i,pivot-1);
        return t;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++) {
            m[inorder[i]]=i;
        }
        
        return helper(inorder,postorder,0,postorder.size()-1);
    }
};