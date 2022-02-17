class Solution {
public:
    void solve(vector<vector<int>>&res,vector<int>&t,vector<int>& candidates,int target,int i) {
        if(target==0) {
            res.push_back(t);
            return;
        }
        
        if(i>=candidates.size() || target<0)
            return;
        
        t.push_back(candidates[i]);
        solve(res,t,candidates,target-candidates[i],i+1);
        t.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1])
            i++;
        solve(res,t,candidates,target,i+1);
        return;
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        //map<vector<int>,int>mp;
        vector<int>t;
        vector<vector<int>>res;
        solve(res,t,candidates,target,0);
        return res;
    }
};