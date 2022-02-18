class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char>q;
        int n=num.length();
        if(n==k)
            return "0";
        int i=0;
        while(i<n) {
            while(k>0 && !q.empty() && q.back()>num[i]) {
                q.pop_back();
                k--;
            }
            q.push_back(num[i]);
            i++;
        }
        
        while(k>0) {
            q.pop_back();
            k--;
        }
        
       // cout<<int(q.front())<<endl;
        
        while(q.size()>1 && q.front()-'0'==0) {
            q.pop_front();
        }
        
        string res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop_front();
        }
        return res;
    }
};