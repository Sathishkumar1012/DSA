class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto p:stones) {
            pq.push(p);
        }
        
        while(pq.size()>1) {
            int t=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            int temp=t-s;
            if(temp!=0) 
                pq.push(temp);
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};