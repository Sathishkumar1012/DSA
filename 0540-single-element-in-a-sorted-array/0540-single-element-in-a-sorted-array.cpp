class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int l=0;
        int h=a.size()-1;
        
        while(l<h) {
           int mid=(l+h)>>1;
           if(a[mid]==a[mid^1])
               l=mid+1;
            else
                h=mid;
           // cout<<a[mid]<<endl;
        }
        return a[l];
    }
};