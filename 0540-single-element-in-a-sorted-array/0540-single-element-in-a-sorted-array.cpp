class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l=0;
        int h=a.size()-1;
        
        while(l<h) {
            int mid=l+(h-l)/2;
            if(mid==0 || mid==a.size()-1)
                return a[mid];
            if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1])
                return a[mid];
            
            if(mid%2==1) {
                if(a[mid-1]==a[mid])
                    l=mid+1;
                else
                    h=mid-1;
            }
            
            else {
                if(a[mid]==a[mid+1])
                    l=mid+1;
                else
                    h=mid-1;
            }
           // cout<<a[mid]<<endl;
        }
        return a[l];
    }
};