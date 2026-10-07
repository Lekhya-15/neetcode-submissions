class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int time=0;
        int fresh=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }

        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty() && fresh>0){
            int size = q.size();
            int push=0;
            while(size--){
            auto [i,j]=q.front();
            q.pop();

            for(auto vec:dir){
                int nr=i+vec[0];
                int nc=j+vec[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    fresh--;
                }
            }
            }

            time++;
        }
        time=fresh?-1:time;
        
        return time;

    }
};
