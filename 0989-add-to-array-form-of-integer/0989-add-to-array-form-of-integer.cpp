class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        while(i>=0 && k>0) {
            int temp=num[i]+k;
            num[i]=temp%10;
            k=temp/10;
            i--;
        }
        
        while(k>0) {
            num.insert(num.begin(),k%10);
            k=k/10;
        }
        
        return num;
    }
};