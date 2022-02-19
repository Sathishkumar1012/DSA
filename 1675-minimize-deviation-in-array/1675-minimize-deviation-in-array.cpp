class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int minm=INT_MAX;
        for(auto &p:nums) {
            if(p%2!=0)
                p*=2;
            pq.push(p);
            minm=min(minm,p);
        }
        
        int diff=INT_MAX;
        while(pq.top()%2==0) {
            diff=min(diff,pq.top()-minm);
            int top=pq.top()/2;
            minm=min(minm,top);
            pq.pop();
            pq.push(top);
        }
        
        diff=min(diff,pq.top()-minm);
        return diff;
    }
};