class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int m=nums.size();
        int n=m-1;
        while(n>0) {
            if(nums[n]>nums[n-1]) 
                break;
            n--;
        }
        int maxm=n-1;
        if(n==0) {
            reverse(nums.begin(),nums.end());
        }
        
        else {
            int n=m-1;
            while(nums[n]<=nums[maxm]) {
                n--;
            }
            swap(nums[maxm],nums[n]);
           /* int l=maxm+1;
            int h=m-1;
            while(l<h) {
                swap(nums[l],nums[h]);
                l++;
                h--;
            }*/
            reverse(nums.begin()+maxm+1,nums.end());
        }
    }
};