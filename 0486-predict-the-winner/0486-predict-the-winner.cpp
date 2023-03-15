class Solution {
public:
    int helper(int i,vector<int>& nums,int j,vector<vector<int>>&dp) {
        if(i>j)
            return 0;
        if(i==j)
            return nums[i];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        dp[i][j]=max(min(helper(i+2,nums,j,dp),
                         helper(i+1,nums,j-1,dp))+nums[i],
                     min(helper(i,nums,j-2,dp),
                         helper(i+1,nums,j-1,dp))+nums[j]);
        return dp[i][j];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        
        for(auto p:nums) {
            sum+=p;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int temp=helper(0,nums,nums.size()-1,dp);
        return sum-temp<=sum/2;
    }
};