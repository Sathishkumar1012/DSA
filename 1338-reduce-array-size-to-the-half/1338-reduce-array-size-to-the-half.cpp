class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b) {
        return a.second>b.second;
    }
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto p:arr) {
            m[p]++;
        }
        
        vector<pair<int,int>>v;
        for(auto k:m) {
            v.push_back(k);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int l=0;
        int res=0;
        
        for(auto p:v) {
            l+=p.second;
            res++;
            if(l>=arr.size()/2)
                break;       
        }
        
        return res;
    }
};