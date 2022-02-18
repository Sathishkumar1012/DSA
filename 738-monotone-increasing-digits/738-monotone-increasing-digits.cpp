class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string temp=to_string(n);
        int spot=temp.length();
        for(int i=temp.length()-1;i>0;i--) {
            if(temp[i]<temp[i-1]) {
                spot=i;
                temp[i-1]-=1;
            }
        }
        
        for(int i=spot;i<temp.length();i++) {
            temp[i]='9';
        }
        
        return stoi(temp);
    }
};