class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>res;
        
       /* for(auto p:words) {
            int flag=0;
            unordered_set<char>s;
            unordered_set<char>t;
            unordered_map<char,char>m;
            
            if(p.length()!=pattern.length()) {
                flag=1;
                break;
            }
            
            s.insert(p[0]);
            t.insert(pattern[0]);
            m[pattern[0]]=p[0];
            for(int i=1;i<pattern.length();i++) {
                if(t.count(pattern[i])!=0 && m[pattern[i]]!=p[i]) {
                    flag=1;
                    break;
                }
                
                if(t.count(pattern[i])==0 && s.count(p[i])!=0) {
                    flag=1;
                    break;
                }
                
                s.insert(p[i]);
                t.insert(pattern[i]);
                m[pattern[i]]=p[i];
            }
            
            if(flag==0)
                res.push_back(p);
        }*/
        
        unordered_map<char,int>m;
        unsigned long long check=1;
        int l=1;
        m[pattern[0]]=1;
        for(int i=1;i<pattern.length();i++) {
            if(m[pattern[i]]!=0) {
                check=(check*10)+m[pattern[i]];
            }
            
            else {
                l++;
                check=check*10+l;
                m[pattern[i]]=l;
            }
        }
        
        for(auto p:words) {
            m.clear();
            unsigned long long check2=1;
            l=1;
            m[p[0]]=1;
            for(int i=1;i<pattern.length();i++) {
                if(m[p[i]]==0) {
                    l+=1;
                    check2=(check2*10)+l;
                    m[p[i]]=l;
                   
                }
            
                else {
                    check2=(check2*10)+m[p[i]];
                }
            }
            
            //cout<<check<<" "<<check2<<endl;
            
            if(check==check2)
                res.push_back(p);
        }
        
        return res;
    }
};