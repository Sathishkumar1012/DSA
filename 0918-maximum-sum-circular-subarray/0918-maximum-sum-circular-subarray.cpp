class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curmin,curmax,tmax,tmin,total;
        curmin=0;
        tmin=INT_MAX;
        curmax=0;
        tmax=INT_MIN;
        total=0;
        for(auto p:nums) {
            curmax=max(curmax+p,p);
            tmax=max(tmax,curmax);
            
            curmin=min(curmin+p,p);
            tmin=min(curmin,tmin);
            
            total+=p;
        }
        cout<<tmax<<" "<<tmin<<" "<<total<<endl;
        
        return tmax>0?max(tmax,total-tmin):tmax;
    }
};