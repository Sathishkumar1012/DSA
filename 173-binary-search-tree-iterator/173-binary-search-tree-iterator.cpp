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
class BSTIterator {
public:
    stack<TreeNode*>temp;
    void store(TreeNode* t) {
        if(!t)
            return;
        temp.push(t);
        store(t->left);
    }
    
    BSTIterator(TreeNode* root) {
        store(root);
    }
    
    int next() {
        TreeNode* s=temp.top();
        temp.pop();
        store(s->right);
        return s->val;
        
    }
    
    bool hasNext() {
        return !temp.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */