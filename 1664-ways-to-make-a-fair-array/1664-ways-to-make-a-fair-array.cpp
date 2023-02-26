class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int>os(n,0);
        vector<int>es(n,0);
        int osum,esum;
        osum=esum=0;
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                esum+=nums[i];
            }
            else
                osum+=nums[i];
            os[i]=osum;
            es[i]=esum;
        }
        
        int count=0;
        
        for(int i=0;i<n;i++) {
            if(i==0) {
                osum=es[n-1]-nums[0];
                esum=os[n-1];
                if(esum==osum)
                    count++;
            }
            
            else {
                esum=es[i-1]+(os[n-1]-os[i]);
                osum=os[i-1]+(es[n-1]-es[i]);
                
                if(esum==osum)
                    count++;
            }
        }
        
        return count;
    }
};