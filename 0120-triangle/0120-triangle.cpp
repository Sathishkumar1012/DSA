class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>row(triangle[n-1]);
        vector<int>crow(n,0);
        
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<=i;j++) {
                crow[j]=triangle[i][j]+min(row[j],row[j+1]);
                //cout<<crow[j]<<endl;
            }
            swap(crow,row);
        }
        
        return row[0];
    }
};