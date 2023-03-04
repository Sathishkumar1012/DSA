class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        
        for(int i=0;i<nums.size();i++) {
            if(temp.size()==0 || temp.back()<nums[i])
                temp.push_back(nums[i]);
            else{
                auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
                temp[it-temp.begin()]=nums[i];
            }
        }
        
        return temp.size();
    }
};