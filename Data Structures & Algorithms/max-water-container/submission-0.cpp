class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea=0;
        int l=0;
        int r=heights.size()-1;
        while(l<r){
            int length=0;
            int area=0;
            if(heights[l]<heights[r]) length=heights[l];
            else length=heights[r];
            area=length*(r-l);
            maxArea=max(maxArea,area);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return maxArea;
    }
};
