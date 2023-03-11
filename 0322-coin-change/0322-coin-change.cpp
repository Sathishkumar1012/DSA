class Solution {
public:
    
    long long helper(int i,vector<int>& coins, int amount,int n,vector<vector< long long>>&dp) {
        if(i==n)
            return INT_MAX-1;
        if(amount<0)
            return INT_MAX-1;
        if(amount==0)
            return 0;
        if(dp[i][amount]!=INT_MAX)
            return dp[i][amount];
        
        if(coins[i]<=amount)
        dp[i][amount]=min(1+helper(i,coins,amount-coins[i],n,dp),0+helper(i+1,coins,amount,n,dp));
        else
            dp[i][amount]=helper(i+1,coins,amount,n,dp);
        return dp[i][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
         if(amount<=0)
            return 0;
        int n=coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount+1,INT_MAX));
        helper(0,coins,amount,n,dp);
        long long res=INT_MAX;
        for(int i=0;i<n;i++) {
            res=min(res,dp[i][amount]);
        }
        return res>amount?-1:res;
    }
};