class Solution {
public:
    long long check(long long int mid,vector<int>& time) {
        long long temp=0;
        
        for(auto p:time) {
            temp+=(mid/p);
        }
        
        return temp;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int l=*min_element(time.begin(),time.end());
        long long int r=l*totalTrips;
        
        while(l<=r) {
            long long int mid=l+(r-l)/2;
            if(check(mid,time)>=totalTrips) 
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};