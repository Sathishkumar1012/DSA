class Solution {
public:
    int bs(int l,int r,int target,vector<int>nums) {
        while(l<=r) {
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target) 
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int k=bs(0,n-1,target,nums);
        if(k==-1) {
            vector<int>res{-1,-1};
            return res;
        }
        
        int st=k;
        int et=k;
        
        while(st>=0 && nums[st]==target) {
            st--;
        }
        
        st+=1;
        
        while(et<n && nums[et]==target) {
            et++;
        }
        
        et-=1;
        
        vector<int>res;
        res.push_back(st);
        res.push_back(et);
        return res;
        
    }
};