class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        /*int i=num.size()-1;
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
        
        return num;*/
        
        int carry=0;
        vector<int>p;
        while(!num.empty() || k>0) {
            int digit1=num.empty()?0:num.back();
            int digit2=k%10;
            
            int temp=digit1+digit2+carry;
            carry=temp/10;
            
            p.push_back(temp%10);
            
            if(!num.empty())
                num.pop_back();
            k=k/10;
        }
        
        
        if(carry>0) {
            p.push_back(carry);
        }
        
        reverse(p.begin(),p.end());
        return p;
        
    }
};