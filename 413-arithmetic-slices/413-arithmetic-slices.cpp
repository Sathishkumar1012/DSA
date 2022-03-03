class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        int i=0;
        int count=0;
        while(i<n-2) {
            int r=1;
            while(i<n-2 && nums[i+2]-nums[i+1]==nums[i+1]-nums[i]) {
                count+=r;
                r++;
                i++;
            }
            i++;
        }
        return count;
    }
};