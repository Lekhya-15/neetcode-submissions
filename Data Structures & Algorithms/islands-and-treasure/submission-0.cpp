class Solution {
public:
    int valid(int i,int j,vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()) return 1;
        return 0;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }

        while(!q.empty()){
            vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
            pair<int,int> ind=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=ind.first+dir[i][0];
                int nc=ind.second+dir[i][1];
                if(valid(nr,nc,grid) && grid[nr][nc]==INT_MAX){
                    grid[nr][nc]=grid[ind.first][ind.second]+1;
                    q.push({nr,nc});
                }
            }
        }
        return;
    }
};
