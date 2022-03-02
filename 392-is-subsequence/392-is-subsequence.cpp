class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        if(s.empty())
            return true;
        int i=0;
        int j=0;
        while(i<n) {
            if(j==m)
                return true;
            if(s[j]==t[i]){
                j++;
            }
            i++;
        }
        //cout<<i<<j<<endl;
        if(j==m)
            return true;
        return false;
    }
};