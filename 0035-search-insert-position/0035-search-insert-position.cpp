class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        long i=0;
        long j=nums.size()-1;
        long mid=0;
        
        while(i<=j) {
            mid=i+(j-i)/2;
            if(nums[mid]==target)
                return mid;
            
            if(target>nums[mid])
                i=mid+1;
            
            if(target<nums[mid])
                j=mid-1;
        }
        
        return i;
    }
};