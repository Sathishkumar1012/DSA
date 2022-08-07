class Solution {
public:
    int countVowelPermutation(int n) {
        long a,e,i,o,u;
        a=e=i=o=u=1;
        long mod=pow(10,9)+7;
        
        long a1,e1,i1,o1,u1;
        
        int j=2;
        
        while(j<=n) {
            a1=(e+i+u)%mod;
            e1=(a+i)%mod;
            i1=(e+o)%mod;
            o1=i%mod;
            u1=(i+o)%mod;
            
            a=a1;
            e=e1;
            i=i1;
            o=o1;
            u=u1;
            j++;
        }
        return (a+e+i+o+u)%mod;
    }
};