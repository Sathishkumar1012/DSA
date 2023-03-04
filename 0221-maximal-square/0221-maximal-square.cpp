class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
         for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j]=matrix[i][j]-'0';
            }
        }
        
        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                if(dp[i][j]==1)
                    dp[i][j]=min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]))+1;
            }
        }
        
        int res=INT_MIN;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                res=max(res,dp[i][j]);
            }
        }
        
        return res*res;
    }
};