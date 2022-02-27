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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,int>>t;
        t.push({root,0});
        int result=1;
        while(!t.empty()) {
            //long long lmax=INT_MAX;
            //long long rmax=INT_MIN;
            int i=0;
            long long n=t.size();
            int start=t.front().second;
            int end=t.back().second;
            result=max(result,end-start+1);
            while(i<n) {
                TreeNode* temp=t.front().first;
                long long ind=t.front().second-start;
                t.pop();
                if(temp->left) {
                    t.push({temp->left,2*ind+1});
                   // lmax=min(lmax,2*ind+1);
                    //rmax=max(rmax,2*ind+1);
                }
                
                if(temp->right) {
                    t.push({temp->right,2*ind+2});
                   // lmax=min(lmax,2*ind+2);
                    //rmax=max(rmax,2*ind+2);
                }
                i++;
            }
        }
        return result;
    }
};