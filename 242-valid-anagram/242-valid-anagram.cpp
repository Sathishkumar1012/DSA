class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        /*unordered_map<char,int>count;
        for(auto p:s) {
            count[p]++;
        }
        
        for(auto p:t) {
            count[p]--;
        }
        
        for(auto p:count) {
            if(p.second!=0)
                return false;
        }
        return true;*/
        
        vector<int>count(26,0);
        
         for(auto p:s) {
            count[p-'a']++;
        }
        
         for(auto p:t) {
            count[p-'a']--;
        }
        
        for(auto p:count) {
            if(p!=0)
                return false;
        }
        
        return true;
    }
};