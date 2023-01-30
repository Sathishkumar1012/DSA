class Solution {
public:
    int check(int n,vector<int>&dp) {
        if(dp[n]!=INT_MAX)
            return dp[n];
        
        dp[n]=check(n-1,dp)+check(n-2,dp)+check(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        return check(n,dp);
    }
};