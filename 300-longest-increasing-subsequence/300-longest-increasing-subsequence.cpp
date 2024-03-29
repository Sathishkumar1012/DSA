class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxm=INT_MIN;
        for(int i=0;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(nums[j]<nums[i]) {
                    dp[i]=max(dp[i],dp[j]+1);
                    maxm=max(maxm,dp[i]);
                }
            }
        }
        return max(dp[n-1],maxm);
    }
};