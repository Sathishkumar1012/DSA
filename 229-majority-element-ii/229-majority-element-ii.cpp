class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        if(nums.size()==1)
            return nums;
        sort(nums.begin(),nums.end());
        int major=nums[0];
        int i=1;
        int count=1;
        while(i<nums.size()) {
            while(i<nums.size() && major==nums[i]) {
                count++;
                i++;
            }
            if(count>nums.size()/3)
                res.push_back(major);
            if(i<nums.size()) {
                major=nums[i];
                i++;
                count=1;
            }
        }
        if(count==1 && count>nums.size()/3)
            res.push_back(major);
        return res;
    }
};