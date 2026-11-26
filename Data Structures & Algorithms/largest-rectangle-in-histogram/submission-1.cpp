class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        int ans=0;
        for(int i=0;i<n;i++){
            if(i!=0 && heights[i]==heights[i-1]) continue;
            // int h=INT_MAX;
            // for(int j=i;j<n;j++){
            //     h=min(heights[j],h);
            //     ans=max(h*(j-i+1),ans);
            // }
            int l=i;int r=i;
            int h=heights[i];
            while(l-1>=0 && heights[l-1]>=h){
                l--;
            }
            while(r+1<n && heights[r+1]>=h){
                r++;
            }
            ans=max(h*(r-l+1),ans);
        }

        return ans;
    }
};
