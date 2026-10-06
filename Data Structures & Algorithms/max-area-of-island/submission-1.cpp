class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& visit,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1) return 0;
        if(visit[i][j] || grid[i][j]==0) return 0;
        
        visit[i][j]=1;
        return 1 + dfs(i-1,j,visit,grid) + dfs(i,j-1,visit,grid) + dfs(i+1,j,visit,grid) + dfs(i,j+1,visit,grid);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visit(grid.size(),vector<int>(grid[0].size(),0));
        int n=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visit[i][j] && grid[i][j]==1){
                    n=max(n,dfs(i,j,visit,grid));
                }
            }
        }

        return n;
    }
};
