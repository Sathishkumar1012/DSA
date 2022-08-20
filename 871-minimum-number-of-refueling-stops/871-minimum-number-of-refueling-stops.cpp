class Solution {
public:
    int minRefuelStops(int target, int startfuel, vector<vector<int>>& stations) {
        int n=stations.size();
        vector<vector<long long>>temp(n+1,vector<long long>(n+1,0));
        
        for(int j=0;j<=n;j++) {
            temp[0][j]=startfuel;
        }
        
        for(int i=0;i<=n;i++) {
            temp[i][0]=startfuel;
        }
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<=i;j++) {
                temp[i][j]=temp[i-1][j];
                
                if(temp[i-1][j-1]>=stations[i-1][0])
                    temp[i][j]=max(temp[i][j],temp[i-1][j-1]+stations[i-1][1]);
            }
        }
        
        for(int i=0;i<=n;i++) {
            if(temp[n][i]>=target)
                return i;
        }
        return -1;
    }
};