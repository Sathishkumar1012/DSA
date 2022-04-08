class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int t;
    KthLargest(int k, vector<int>& nums) {
        t=k;
        for(auto p:nums) {
            pq.push(p);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>t)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */