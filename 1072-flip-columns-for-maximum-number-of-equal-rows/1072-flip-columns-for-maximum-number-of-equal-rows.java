class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        int res=0;
        
        for(int i=0;i<m;i++) {
            int[] temp=new int[n];
            
            for(int j=0;j<n;j++) {
                temp[j]=1-matrix[i][j];
            }
            int count=0;
            for(int k=0;k<m;k++) {
                if(Arrays.equals(matrix[i],matrix[k]) ||
                  Arrays.equals(matrix[k],temp))
                    count++;
            }
            res=Math.max(res,count);
        }
        
        return res;
    }
}