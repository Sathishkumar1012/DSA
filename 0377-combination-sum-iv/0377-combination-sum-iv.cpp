class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<unsigned int>dp(target+1,0);
        dp[0]=1;
        
        for(int i=1;i<=target;i++) {
            for(auto p:nums) {
                if(i>=p)
                    dp[i]+=dp[i-p];
                else
                    break;
            }
        }
        
        return dp[target];
    }
};