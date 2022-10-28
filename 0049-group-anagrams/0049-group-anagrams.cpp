class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>dup=strs;
        unordered_map<string,vector<int>>group;
        for(int i=0;i<strs.size();i++) {
            sort(strs[i].begin(),strs[i].end());
        }
        
        
        int i=0;
        for(auto p:strs) {
            group[p].push_back(i);
            i++;
        }
        
        vector<vector<string>>anagrams;
        
        for(auto p:group) {
            vector<string>temp;
            for(auto k:p.second) {
                temp.push_back(dup[k]);
            }
            anagrams.push_back(temp);
        }
        return anagrams;
    }
};