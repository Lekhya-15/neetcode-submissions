class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        if(n==1 || n==2) return 0;

        int area=0;

        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        int m=0;
        prefix[1]=0;
        suffix[n-2]=n-1;

        for(int i=2;i<n;i++){
            if(height[i-1]>height[m]) m=i-1;
            prefix[i]=m;
        }

        m=n-1;
        for(int i=n-3;i>=0;i--){
            if(height[i+1]>height[m]) m=i+1;
            suffix[i]=m;
        }

        for(int i=1;i<n-1;i++){
            int x=min(height[prefix[i]],height[suffix[i]])-height[i];
            if(x>0) area+=x;
        }
        return area;
    }
};
