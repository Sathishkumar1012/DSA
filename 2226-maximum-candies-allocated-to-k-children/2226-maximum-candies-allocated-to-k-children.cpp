class Solution {
public:
    long long check(long long mid,vector<int>& candies) {
        long long temp=0;
        
        for(auto p:candies) {
            temp+=(p/mid);
        }
        
        return temp;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long temp=0;
        
        for(auto p:candies) {
            temp+=p;
        }
        
        if(temp<k)
            return 0;
        
        long long l=1;
        long long r=*max_element(candies.begin(),candies.end());
        
        while(l<=r) {
            long long mid=l+(r-l)/2;
            
            if(check(mid,candies)>=k)
                l=mid+1;
            else
                r=mid-1;
        }
        return r;
    }
};