class Solution {
public:
    struct comp{
       bool operator()(pair<int,int>&a,pair<int,int>&b) {
           return a.second>b.second;
       } 
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto p:nums) {
            mp[p]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(auto it=mp.begin();it!=mp.end();it++) {
            pq.push({it->second,it->first});
        }
        
        
        vector<int>res;
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};