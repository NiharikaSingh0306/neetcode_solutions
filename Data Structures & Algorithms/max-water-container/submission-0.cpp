class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater=0;
        int n=heights.size();
        int i=0;
        int j=n-1;
        int minh=INT_MAX;
        while(i<j){
            int width=j-i;
            minh=min(heights[i],heights[j]);

            maxWater=max(maxWater,minh*width);

            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return maxWater;
    }
};
