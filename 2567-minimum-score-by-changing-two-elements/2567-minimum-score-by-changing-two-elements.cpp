class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return min({abs(nums[0]-nums[n-3]),abs(nums[2]-nums[n-1]),abs(nums[1]-nums[n-2])});
    }
};