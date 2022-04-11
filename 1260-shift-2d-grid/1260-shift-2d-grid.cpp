class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>res(r,vector<int>(c,0));
        int t=r*c;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                int temp=i*c+j;
                int nt=(temp+k)%t;
                
                int nr=nt/c;
                int nc=nt%c;
                
                res[nr][nc]=grid[i][j];
            }
        }
        return res;
    }
};