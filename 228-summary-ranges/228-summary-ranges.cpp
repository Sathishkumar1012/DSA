class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int i=0;
        int n=nums.size();
        if(n==0)
            return res;
        while(i<n) {
            int st=i;
            int end=i;
            while(i<n-1 && nums[i]==nums[i+1]-1) {
                i++;
                end++;
            }
            if(st==end)
                res.push_back(to_string(nums[end]));
            else
                res.push_back(to_string(nums[st])+"->"+to_string(nums[end]));
            i++;
        }
        return res;
    }
};