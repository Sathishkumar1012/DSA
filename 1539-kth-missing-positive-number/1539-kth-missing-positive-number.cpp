class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int i=1;
        int j=0;
        int count=0;
        
        while(i<=arr[n-1]) {
            if(i!=arr[j])
                count++;
            else
                j++;
            
            if(count==k)
                return i;
            i++;
        }
        count++;
      //  cout<<count<<"***"<<i<<endl;
        while(count<k) {
            i++;
            count++;
        }
        
        return i;
    }
};