class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, target);
        return ans;
    }
    void helper(int index,vector<int>& candidates, int target){
        
        if(target == 0){
            ans.push_back(temp);
            return; 
        }
        
        if(index==candidates.size())
            return;
        
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            
            if(target>=candidates[i]) {
            temp.push_back(candidates[i]);
            helper(i+1,candidates, target-candidates[i]);
            temp.pop_back();
            }
            
            else
                break;
        }
    }
};