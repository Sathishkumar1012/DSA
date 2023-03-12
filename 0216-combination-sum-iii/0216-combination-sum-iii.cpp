class Solution {
public:
    vector<int>temp;
    vector<vector<int>>res;
    
    void helper(int i,int n,int target,int k) {
        if(target==0 && temp.size()==k) {
            res.push_back(temp);
            return;
        }
        
        if(i==n)
            return;
        
        for(int j=i;j<n && j<=9;j++) {
            if(target>=j) {
                temp.push_back(j);
                helper(j+1,n,target-j,k);
                temp.pop_back();
            }
            else
                break;
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        int target=n;
        helper(1,n,target,k);
        return res;
    }
};