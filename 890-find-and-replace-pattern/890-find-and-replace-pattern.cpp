class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>res;
        
        for(auto p:words) {
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
        }
        return res;
    }
};