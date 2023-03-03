class Solution {
public:
    int strStr(string s, string t) {
        if(t.length()==0)
            return 0;
        
        if(t.length()>s.length())
            return -1;
        
        for(int i=0;i<s.length()-t.length()+1;i++) {
            for(int j=0;j<t.length();j++) {
                if(t[j]!=s[i+j])
                    break;
                
                if(j==t.length()-1)
                    return i;
            }
        }
        return -1;
    }
};