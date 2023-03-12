class Solution {
public:
    vector<int>temp;
    vector<vector<int>>res;
    
    void helper(int i,int target,vector<int>& candidates) {
        if(i==candidates.size())
            return;
        if(target==0) {
            res.push_back(temp);
            return;
        }
        
        for(int j=i;j<candidates.size();j++) {
            if(target>=candidates[j]) {
                temp.push_back(candidates[j]);
                helper(j,target-candidates[j],candidates);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        helper(0,target,candidates);
        return res;
    }
};