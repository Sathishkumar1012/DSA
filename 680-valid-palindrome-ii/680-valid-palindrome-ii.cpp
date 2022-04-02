class Solution {
public:
    bool check(string s,int l,int h) {
        while(l<h) {
            if(s[l]!=s[h])
                return false;
            else {
                l++;
                h--;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int count=0;
        int l=0;
        int h=s.length()-1;
        while(l<h) {
            if(s[l]==s[h]) {
                l++;
                h--;
            }
            else {
            int a=l;
            int b=h;
            if(check(s,a+1,b))
                return true;
            else if(check(s,a,b-1))
                return true;
            return false;
            }
        }
        return true;
    }
};