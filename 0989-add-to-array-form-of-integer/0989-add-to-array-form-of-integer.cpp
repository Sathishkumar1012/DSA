class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>res;
        /*string temp="";
        int rem=0;
        
        int i=num.size()-1;
        
        while(i>=0 && k>0) {
            int t=num[i]+(k%10)+rem;
            temp=char((t%10))+temp;
            rem=t/10;
            k=k/10;
            i--;
        }
        
        if(k>0) {
            temp=char(k+rem)+temp;
            k=k/10;
            
            if(k>0)
                temp=to_string(k)+temp;
        }
        
        else if(i>=0) {
            while(i>=0) {
                int t=num[i]+rem;
                temp=char((t%10))+temp;
                rem=t/10;
                i--;
            }
        }
        
        
        if(rem>0)
            temp=char(rem)+temp;
        
        int j=0;
        while(j<temp.length()) {
            res.push_back(temp[j]);
            j++;
        }*/
        
        int m=num.size();
        int p=k;
        int n=0;
        int rem=0;
        
        while(p>0) {
            n++;
            p=p/10;
        }
        
        string s=to_string(k);
        string t;
        for(int x : num) {
            t.push_back(x + '0');
        };
        
        
        if(m>n) {
            while(m>n) {
                s='0'+s;
                n++;
            }
        }
        
        else if(n>m) {
            while(n>m) {
                t='0'+t;
                m++;
            }
        }
        
        
        s='0'+s;
        t='0'+t;
        
        //cout<<s<<endl;
        //cout<<t<<endl;
        
        int l=s.length()-1;
        
        while(l>=0) {
            int x=(s[l]-'0')+(t[l]-'0')+rem;
            rem=x/10;
            res.push_back(x%10);
            l--;
        }
        
        if(res.size()>1 && res[res.size()-1]==0)
            res.pop_back();
        
        reverse(res.begin(),res.end());
        return res;
    }
};