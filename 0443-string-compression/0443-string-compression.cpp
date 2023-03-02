class Solution {
public:
    int compress(vector<char>& s) {
        if(s.size()==1)
            return 1;
        vector<long>count(94,0);
        vector<char>res;
        
        int n=s.size();
        
        res.push_back(s[0]);
        char b=s[0];
        count[s[0]-'!']=1;
        int i=1;
        
        while(i<n) {
            while(i<n && s[i]==b) {
                count[s[i]-'!']+=1;
                i++;
            }
            
            for(int i=0;i<94;i++) {
                if(count[i]>1) {
                    string t=to_string(count[i]);
                    //cout<<t<<endl;
                    int j=0;
                    while(j<t.length()) {
                        res.push_back(t[j]);
                        //cout<<t[j]<<endl;
                        j++;
                    }
                }
            }
            
            count[b-'!']=0;
            
            if(i<n) {
                res.push_back(s[i]);
                b=s[i];
                count[b-'!']=1;
            }
            
            i++;
        }
       /* for(auto p:res){
            cout<<p<<"--";
        }
        cout<<endl;*/
        s=res;
        return s.size();
    }
};