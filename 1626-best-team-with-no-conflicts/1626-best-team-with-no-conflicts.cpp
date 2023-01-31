class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
            
        vector<pair<int,int>>temp;
        for(int i=0;i<ages.size();i++) {
            temp.push_back({ages[i],scores[i]});
        }
        
        sort(temp.begin(),temp.end(),greater<>());
        int ans=0;
        
        vector<int>dp(ages.size());
        for(int i=0;i<ages.size();i++) {
            dp[i]=temp[i].second;
            for(int j=0;j<i;j++) {
                if(temp[j].second>=temp[i].second) {
                    dp[i]=max(dp[i],dp[j]+temp[i].second);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};