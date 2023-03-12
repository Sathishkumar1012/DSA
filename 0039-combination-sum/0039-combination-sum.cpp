class Solution {
public:
    vector<vector<int>>res;
    vector<int>temp;
    void helper(int i,int target,vector<int>& candidates) {
       // if(i==candidates.size())
        //    return;
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
            
            else
                break;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        //vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(0,target,candidates);
        return res;
    }
};