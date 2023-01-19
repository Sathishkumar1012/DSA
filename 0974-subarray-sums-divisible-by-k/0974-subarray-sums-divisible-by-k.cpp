class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>temp(k,0);
        temp[0]=1;
        
        int total=0;
        int count=0;
        for(auto p:nums) {
            total+=p;
            int rem=total%k;
            if(rem<0)
                rem+=k;
            count+=temp[rem];
            temp[rem]++;
        }
        return count;
    }
};