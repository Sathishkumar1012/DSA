class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,long>m;
        int mod=pow(10,9)+7;
        
        for(auto it:arr) {
            m.insert({it,1});
        }
        cout<<m[arr[1]]<<endl;
        
        for(int i=1;i<arr.size();i++) {
          //  int count=1;
            for(int j=0;j<i;j++) {
                if(arr[i]%arr[j]==0 && m[arr[i]/arr[j]]!=0) {
                    m[arr[i]]+=(m[arr[j]] * m[arr[i]/arr[j]])%mod;
                }
            }
        }
        
        int res;
        
        for(auto p:m){
            res=(res+p.second)%mod;
        }
        
        return res;
    }
};