class Solution {
public:
    void merge(int l,int mid,int r,vector<int>& nums) {
        vector<int>left;
        vector<int>right;
        
     /*   cout<<l<<" "<<mid<<" "<<r<<endl;*/
        
        for(int i=l;i<=mid;i++) {
            left.push_back(nums[i]);
        }
        
        for(int i=mid+1;i<=r;i++) {
            right.push_back(nums[i]);
        }
        
        /*for(auto p:left) {
            cout<<p<<" ";
        }
        cout<<endl;
        
        cout<<"****"<<endl;
        
        for(auto p:right) {
            cout<<p<<" ";
        }
        cout<<endl;*/
        
        
        int s=l;
        int t,u;
        t=u=0;
        
        while(t<left.size() && u<right.size()) {
            if(left[t]<=right[u]) {
                nums[s]=left[t];
                t++;
                s++;
            }
            
            else {
                nums[s]=right[u];
                u++;
                s++;
            }
        }
        
        while(t<left.size()) {
            nums[s]=left[t];
            t++;
            s++;
        }
        
        while(u<right.size()) {
            nums[s]=right[u];
            u++;
            s++;
        }
        
      /* for(auto p:nums) {
            cout<<p<<" ";
        }
        cout<<endl;*/
        
        return;
    }
    
    void mergesort(int l,int r,vector<int>& nums) {
        if(l>=r)
            return;
        int mid=l+(r-l)/2;
        mergesort(l,mid,nums);
        mergesort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        
        mergesort(l,r,nums);
        return nums;
    }
};