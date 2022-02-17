class Solution {
public:
    void solve(vector<vector<int>>&res,vector<int>&t,vector<int>& candidates,int i,int sum) {
        if(i==candidates.size())
            return;
        if(sum<0)
            return;
        if(sum==0) {
            res.push_back(t);
            return;
        }
        t.push_back(candidates[i]);
        solve(res,t,candidates,i,sum-candidates[i]);
        t.pop_back();
        solve(res,t,candidates,i+1,sum);
        //t.pop_back();
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<int>t;
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        solve(res,t,candidates,0,target);
        return res;
    }
};