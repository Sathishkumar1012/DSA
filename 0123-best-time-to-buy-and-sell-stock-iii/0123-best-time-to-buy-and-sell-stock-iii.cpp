class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=prices.size()-1;i>=0;i--) {
        for(int buy=0;buy<2;buy++) {
        for(int limit=1;limit<=2;limit++) {
        if(buy) {
            int b=-prices[i]+dp[i+1][0][limit];
            int s=0+dp[i+1][1][limit];
            dp[i][buy][limit]=max(b,s);
        }
        
        else {
            int b=prices[i]+dp[i+1][1][limit-1];
            int s=0+dp[i+1][0][limit];
            dp[i][buy][limit]=max(b,s);
        }
        }
        }
        }
        return dp[0][1][2];
    }
};