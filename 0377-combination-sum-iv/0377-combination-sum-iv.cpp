class Solution {
public:
    int helper(vector<int>& nums,int n,int target,vector<int>&dp) {
        if(target==0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        
        int res=0;
        for(int i=0;i<n;i++) {
            if(target>=nums[i])
            res+=helper(nums,n,target-nums[i],dp);
        }
        dp[target]=res;
        return dp[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return helper(nums,n,target,dp);
    }
};