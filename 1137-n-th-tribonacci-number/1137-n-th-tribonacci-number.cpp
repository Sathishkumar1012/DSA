class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        int i=3;
        int a,b,c,d;
        a=0;
        b=1;
        c=1;
        while(i<=n) {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
            i++;
        }
        return d;
    }
};