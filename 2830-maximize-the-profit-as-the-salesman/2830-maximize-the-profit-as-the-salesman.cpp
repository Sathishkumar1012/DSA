class Solution {
public:
    int solve(int i,int m,vector<vector<int>>& offers,vector<int>&dp) {
        if(i==m)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int not_take = solve(i+1,m,offers,dp);
        
        int low=i+1;
        int high=m-1;
        
        int ind=m;
        
        while(low<=high) {
            int mid=low+(high-low)/2;
            
            if(offers[mid][0]>offers[i][1]) {
                high=mid-1;
                ind=mid;
            }
            
            else
                low=mid+1;
        }
        
        int take=offers[i][2]+solve(ind,m,offers,dp);
        return dp[i]=max(take,not_take);
        
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m=offers.size();
        int i=0;
        sort(offers.begin(),offers.end());
        
        vector<int>dp(m,-1);
        return solve(0,m,offers,dp);
    }
};