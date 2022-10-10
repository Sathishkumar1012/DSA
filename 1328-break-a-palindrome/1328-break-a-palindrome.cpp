class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(n==1) 
            return "";
        int i=0;
        
        while(i<n) {
            if(palindrome[i]!='a' && i!=n/2) {
                palindrome[i]='a';
                return palindrome;
            }
            i++;
        }
        
        palindrome[n-1]='b';
        return palindrome;
        
    }
};