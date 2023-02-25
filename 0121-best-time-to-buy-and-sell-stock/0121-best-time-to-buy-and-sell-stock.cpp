class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        int n=prices.size();
        int i=0;
        
        while(i<n) {
            if(prices[i]<buy)
                buy=prices[i];
            else
                profit=max(profit,prices[i]-buy);
            i++;
        }
        
        return profit;
    }
};