class Solution {
public:
    void dfs(int i,int j,int o,vector<vector<int>>& height,vector<vector<vector<int>>>& ocean){
        int m=height.size();
        int n=height[0].size();
        if(ocean[i][j][o]) return;

        ocean[i][j][o]++;
        if(i+1<m && height[i+1][j]>=height[i][j]) dfs(i+1,j,o,height,ocean);
        if(i-1>=0 && height[i-1][j]>=height[i][j]) dfs(i-1,j,o,height,ocean);
        if(j+1<n && height[i][j+1]>=height[i][j]) dfs(i,j+1,o,height,ocean);
        if(j-1>=0 && height[i][j-1]>=height[i][j]) dfs(i,j-1,o,height,ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<vector<int>>> ocean(m,vector<vector<int>>(n,vector<int>(2,0)));

        for(int i=0;i<m;i++){
            dfs(i,0,0,heights,ocean);
            dfs(i,n-1,1,heights,ocean);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,0,heights,ocean);
            dfs(m-1,j,1,heights,ocean);
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ocean[i][j][0] && ocean[i][j][1]) ans.push_back({i,j});
            }
        }

        return ans;
    }
};
