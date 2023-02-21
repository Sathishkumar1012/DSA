class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<int>tables;
        set<string>foods;
        map<pair<int,string>,int>m;
        
        for(auto p:orders) {
            tables.insert(stoi(p[1]));
            foods.insert(p[2]);
            pair<int,string>k;
            k=make_pair(stoi(p[1]),p[2]);
            
            m[k]++;
        }
        
        vector<vector<string>>result;
        vector<string>t;
        t.push_back("Table");
        for(auto l:foods) {
            t.push_back(l);
        }
        
        result.push_back(t);
        
        
        for(auto p:tables) {
            vector<string>l;
            l.push_back(to_string(p));
            
            for(auto k:foods) {
                pair<int,string>s;
                s=make_pair(p,k);
                l.push_back(to_string(m[s]));
            }
            result.push_back(l);
        }
        
        return result;
    }
};