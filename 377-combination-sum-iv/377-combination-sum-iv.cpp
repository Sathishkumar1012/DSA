class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        vector<long double> dp(target+1, 0);
        dp[0] = 1;
        
        for(int i=1;i<=target;i++){
            
            for(auto &num : nums){
                if(i-num >= 0){
                    dp[i] += dp[i-num];
                }
            }
        }
        
        return (int)dp[target];
    }
};