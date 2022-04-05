class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxm=INT_MIN;
        int i=0;
        int j=height.size()-1;
        int temp;
        while(i<j) {
            if(height[i]>height[j]) {
                maxm=max(maxm,(j-i)*height[j]);
                j--;
            }
            else {
                maxm=max(maxm,(j-i)*height[i]);
                i++;
            }
        }
        return maxm;
    }
};