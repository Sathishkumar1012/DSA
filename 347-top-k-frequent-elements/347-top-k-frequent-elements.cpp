class Solution {
public:
    struct comp{
       bool operator()(pair<int,int>&a,pair<int,int>&b) {
           return a.second<b.second;
       } 
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(auto p:nums) {
            mp[p]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto it=mp.begin();it!=mp.end();it++) {
            pq.push({it->second,it->first});
            if(pq.size()>k) {
                pq.pop();
            }
            
        }
        
        
        while(k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};