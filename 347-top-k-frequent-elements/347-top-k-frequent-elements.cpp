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
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        
       /* if(mp.size()==1) {
            res.push_back(nums[0]);
            return res;
        }*/
        
        for(auto it=mp.begin();it!=mp.end();it++) {
            //cout<<it->first<<"->"<<it->second<<endl;
            pq.push({it->first,it->second});
        }
        
        
        while(k--) {
            res.push_back(pq.top().first);
            //cout<<pq.top().first<<endl;
            pq.pop();
        }
        
        return res;
    }
};