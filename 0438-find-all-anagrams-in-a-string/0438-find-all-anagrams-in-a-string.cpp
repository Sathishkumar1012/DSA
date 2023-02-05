class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>t(26,0);
        vector<int>res;
        int m=s.length();
        int n=p.length();
        if(m<n)
            return res;
        for(auto k:p) {
            t[k-'a']++;
        }
        
        int i=0;
        vector<int>v(26,0);
        while(i<n) {
            v[s[i]-'a']++;
            i++;
        }
        
        if(t==v) {
            res.push_back(0);
        }
        
        v[s[i-n]-'a']--;
        
        while(i<m) {
            v[s[i]-'a']++;
            if(t==v) {
                res.push_back(i-(n-1));
            }
            v[s[i-(n-1)]-'a']--;
            i++;
        }
        return res;
    }
};