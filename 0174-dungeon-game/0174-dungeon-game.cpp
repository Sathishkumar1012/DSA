class Solution {
public:
    int m,n;
    int helper(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>>&dp) {
        if(i==dungeon.size() || j==dungeon[0].size())
            return INT_MAX;
        if(i==m-1 && j==n-1)
            return dungeon[i][j]<=0 ? 1-dungeon[i][j]:1;
        
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        int right=helper(i,j+1,dungeon,dp);
        int down=helper(i+1,j,dungeon,dp);
        
        int temp=min(right,down)-dungeon[i][j];
        
        dp[i][j]=temp<=0?1:temp;
        return dp[i][j];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        return helper(0,0,dungeon,dp);
    }
};