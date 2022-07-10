class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2) {
            return min(cost[0],cost[1]);
        }
        
        if(n==3) {
            return min(cost[1],cost[0]+cost[2]);
        }
        
        vector<int>pay(n,0);
        pay[n-1]=cost[n-1];
        pay[n-2]=cost[n-2];
        int i=n-3;
        
        while(i>=0) {
            pay[i]=cost[i]+min(pay[i+1],pay[i+2]);
            i--;
        }
        return min(pay[0],pay[1]);
    }
};