class Solution {
public:
    int minDistance(string word1, string word2) {
        int m,n;
       /* if(word1.length()>word2.length()) {
            string temp=word1;
            word1=word2;
            word2=temp;
        }
        */
        m=word1.length();
        n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        
        for(int i=0;i<=m;i++) {
            for(int j=0;j<=n;j++) {
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                
                else 
                    dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
        return dp[m][n];
    }
};