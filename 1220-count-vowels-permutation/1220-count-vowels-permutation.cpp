class Solution {
public:
    int countVowelPermutation(int n) {
        if(n==1)
            return 5;
        int mod=1e9+7;
        long long pa,pe,pi,po,pu;
        pa=pe=pi=po=pu=1;
        long long ca,ce,ci,co,cu;
        int i=2;
        int res=0;
        while(i<=n) {
            ca=pe+pu+pi;
            ce=pa+pi;
            ci=pe+po;
            co=pi;
            cu=pi+po;
            
            ca=ca%mod;
            ce=ce%mod;
            ci=ci%mod;
            co=co%mod;
            cu=cu%mod;
            //res=ca+ci+ce+co+cu;
            pa=ca;
            pe=ce;
            pi=ci;
            po=co;
            pu=cu;
           // cout<<pa<<" "<<pe<<" "<<pi<<" "<<po<<" "<<pu<<endl;
            i++;
        }
        //cout<<res<<endl;
        return (pa+pe+pi+po+pu)%mod;
    }
};