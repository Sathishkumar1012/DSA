class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        vector<string>st;
        int j=0;
        string res="";
        while(i<n) {
            while(i<n && s[i]==' ') {
                i++;
            }
            
            if(i<n) {
                string t;
                while(i<n && s[i]!=' ') {
                    t.push_back(s[i]);
                    i++;
                }
                st.push_back(t);
            }
            i++;
        }
        
        n=st.size()-1;
        
        
        while(n>=0) {
            res+=st[n];
            res.push_back(' ');
            n--;
        }
        
        if(res.length()>0)
            res.pop_back();
        return res;
    }
};