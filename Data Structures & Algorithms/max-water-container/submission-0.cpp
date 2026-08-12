class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0;int r=n-1;

        int max=0;
        while(l<r){
            int area=(r-l)*(min(heights[l],heights[r]));
            if(max<area) max=area;
            if(heights[r]>heights[l]){
                l++;
            }
            else{
                r--;
            }
        }

        return max;
    }
};
