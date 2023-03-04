class Solution {
public:
    int helper(vector<int>&dp,int n) {
        if(n==0)
            return 0;
        
        if(dp[n]!=INT_MAX)
            return dp[n];
        
        for(int i=1;i<=sqrt(n);i++) {
            int p=i*i;
            dp[n]=min(dp[n],n/p+helper(dp,n%p));
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        if(n==1)
            return 1;
        vector<int>dp(n+1,INT_MAX);
        for(int i=1;i<=sqrt(n);i++) {
            dp[i*i]=1;
        }
        return helper(dp,n);
    }
};