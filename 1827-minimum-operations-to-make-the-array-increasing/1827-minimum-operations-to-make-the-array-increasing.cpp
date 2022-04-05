class Solution {
public:
    int minOperations(vector<int>& nums) {
        /*if(nums.size()==1)
            return 0;
        if(nums.size()==2) {
            if(nums[1]<=nums[0])
                return nums[0]-nums[1]+1;
            return 0;
        }
        
        int count=0;
        int i=1;
        while(i<nums.size()) {
            while(i<nums.size() && nums[i]>nums[i-1]) {
                i++;
            }
            
            if(i==nums.size())
                return count;
            count+=nums[i-1]-nums[i]+1;
            nums[i]=nums[i-1]+1;
            i++;
        }
        return count;*/
        int res = 0, last = 0;
        for (auto n : nums) {
            res += max(0, last - n + 1);
            last = max(n, last + 1);
        }
        return res;
    }
};