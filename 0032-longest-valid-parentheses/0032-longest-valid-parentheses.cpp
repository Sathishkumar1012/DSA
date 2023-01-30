class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int maxm=0;
        vector<int>dp(n,0);
        int i=1;
       // stack<int>s;
        while(i<n) {
            if(s[i] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                    dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2 >= 0)?dp[i-dp[i-1]-2]:0);
                    maxm = max(dp[i],maxm);
            }
            i++;
        }
        return maxm;
    }
};