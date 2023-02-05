class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        
        if(m>n)
            return false;
        unordered_set<char>s;
        vector<int>temp(26,0);
        for(auto p:s1) {
            temp[p-'a']++;
        }
        
        int count;
        int i=0;
        vector<int>t(26,0);
        /*count=0;
        while(i<m) {
            t[s2[i]-'a']++;
            //cout<<"***"<<t[s2[i]-'a']<<endl;
            if(temp[s2[i]-'a']>0) {
                if(t[s2[i]-'a']<=temp[s2[i]-'a'])  {
                    s.insert(s2[i]);
                    count++;
                }
            }
            else {
                s.clear();
                count=0;
            }
            i++;
        }
        
        if(count==m)
            return true;
       
        t[s2[i-m]-'a']--;
        if(t[s2[i-(m)]-'a']<temp[s2[i-(m)]-'a'] && s.count(s2[i-m])>0)
                count--;
        
       // cout<<"..."<<count<<endl;
         //cout<<s2[i-m]<<" "<<t[s2[i-m]-'a']<<endl;
        
        while(i<n) {
            t[s2[i]-'a']++;
            if(temp[s2[i]-'a']>0) {
                if(t[s2[i]-'a']<=temp[s2[i]-'a']) {
                    s.insert(s2[i]);
                    count++;
                }
            }
            else {
                s.clear();
                count=0;
            }
            if(count==m)
            return true;
            t[s2[i-(m-1)]-'a']--;
            if(t[s2[i-(m-1)]-'a']<temp[s2[i-(m-1)]-'a'] && s.count(s2[i-(m-1)])>0)
                count--;
           // cout<<s2[i-(m-1)]<<"  "<<t[s2[i-(m-1)]-'a']<<endl;
            //cout<<"..."<<count<<endl;
            i++;
        }
        
        return false;*/
    
        while(i<m) {
            t[s2[i]-'a']++;
            i++;
        }
        
        if(t==temp)
            return true;
        t[s2[i-m]-'a']--;
        
        
        while(i<n) {
            t[s2[i]-'a']++;
            if(t==temp)
                return true;
            t[s2[i-(m-1)]-'a']--;
            i++;
        }
        return false;
    }
};