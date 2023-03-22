class Solution {
public:
    int result=INT_MAX;
    
    void helper(vector<bool>&vis,vector<vector<pair<int,int>>>&temp,int i) {
        if(vis[i])
            return;
        vis[i]=true;
        
        for(auto &[v,dis]:temp[i]) {
            result=min(result,dis);
            helper(vis,temp,v);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>temp(n+1);
        for(auto p:roads) {
            temp[p[0]].push_back({p[1],p[2]});
            temp[p[1]].push_back({p[0],p[2]});
        }
        
        vector<bool>vis(n+1,false);
        
        helper(vis,temp,1);
        return result;
    }
};
