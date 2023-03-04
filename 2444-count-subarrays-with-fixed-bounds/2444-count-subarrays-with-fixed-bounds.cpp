class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        long long res=0;
        int s=-1,e=-1,d=-1;
        
        int i=0;
        while(i<nums.size()) {
            if(nums[i]>maxk || nums[i]<mink)
                d=i;
            if(nums[i]==mink)
                s=i;
            if(nums[i]==maxk)
                e=i;
            
            //res+=max(0L,min(s,e)-d);
             res += max(0, min(s, e)-d);
            i++;
        }
        return res;
    }
};