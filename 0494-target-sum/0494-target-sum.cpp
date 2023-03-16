class Solution {
public:
    int res=0;
    
    void helper(int i,int target,vector<int>& nums) {
        if(i==nums.size() && target==0) {
            res++;
            return;
        }
        
        if(i==nums.size())
            return;
        
        helper(i+1,target-nums[i],nums);
        helper(i+1,target+nums[i],nums);
        return;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(0,target,nums);
        return res;
    }
};