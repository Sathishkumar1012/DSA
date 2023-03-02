class Solution {
public:
    int compress(vector<char>& s) {
        int n=s.size();
        if(n==1)
            return 1;
        int i,j;
        i=1;
        j=1;
        char t=s[0];
        int count=1;
        s[0]=s[0];
        
        while(i<n) {
            while(i<n && s[i]==t) {
                count++;
                i++;
            }
            
            
            if(count>1) {
                string t=to_string(count);
                for(auto p:t) {
                    s[j]=p;
                    j++;
                }
            }
            
            
            if(i<n) {
               s[j]=s[i];
                j++;
                count=1;
                t=s[i];
            }
            
            i++;
        }
        return j;
    }
};