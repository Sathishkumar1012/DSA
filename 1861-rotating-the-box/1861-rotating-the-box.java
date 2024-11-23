class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m=box.length;
        int n=box[0].length;
        
        int k=0;
        while(k<m) {
            int j=n-1;
            while(j>=0) {
            while(j>=0 && box[k][j]!='.') {
                j--;
            }
            
            int i=j;
            
            while(i>=0 && box[k][i]!='#') {
                if(box[k][i]=='*' && i>0)
                    j=i-1;
                
                i--;
            }
            
            if(i>=0) {
                box[k][i]='.';
                box[k][j]='#';
            }
                j--;
            }
            
            k++;
        }
        
        char[][] res=new char[n][m];
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                res[j][i]=box[i][j];
            }
        }
        
        int i=0;
        
        
       //System.out.println(res);
        
        while(i<res.length) {
            k=0;
            int j=res[0].length-1;
            
            
            
            while(k<j) {
                //System.out.println(+" "+)
                char temp=res[i][j];
                res[i][j]=res[i][k];
                res[i][k]=temp;
                k++;
                j--;
            }
            
            i++;
        }
        
        return res;
    }
}