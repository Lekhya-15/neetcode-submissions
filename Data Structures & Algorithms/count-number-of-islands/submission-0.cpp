class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& visit,vector<vector<char>>& grid){
        if(visit[i][j] || grid[i][j]== '0') return;
        
        visit[i][j]=1;
        if(i>0) dfs(i-1,j,visit,grid);
        if(j>0) dfs(i,j-1,visit,grid);
        if(i<grid.size()-1) dfs(i+1,j,visit,grid);
        if(j<grid[0].size()-1) dfs(i,j+1,visit,grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visit(grid.size(),vector<int>(grid[0].size(),0));
        int n=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visit[i][j] && grid[i][j]=='1'){
                    n++;
                    dfs(i,j,visit,grid);
                }
            }
        }

        return n;
    }
};
