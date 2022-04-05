class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxm=INT_MIN;
        int i=0;
        int j=height.size()-1;
        int temp;
        while(i<j) {
            int minh=min(height[i],height[j]);
            maxm=max(maxm,(j-i)*minh);
            if(height[i]>height[j]) {
                j--;
                while(i<j && height[j]<minh) {
                    j--;
                }
            }
            else {
                i++;
                while(i<j && height[i]<minh) {
                    i++;
                }
            }
        }
        return maxm;
    }
};