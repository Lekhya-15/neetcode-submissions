class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,int m, int n,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }

        if(dp[i][j]) return dp[i][j];

        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

        int l=1;
        for(auto [x,y]:dir){
            if(i+x>=0 && j+y>=0 && i+x<m && j+y<n){
                if(matrix[i+x][j+y]>matrix[i][j]){
                    l=max(1+dfs(i+x,j+y,matrix,m,n,dp),l);
                }
            }
        }
        dp[i][j]=l;
        return l;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        int ma=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!dp[i][j]){
                    dp[i][j]=dfs(i,j,matrix,m,n,dp);
                }
                ma=max(ma,dp[i][j]);
            }
        }
        return ma;
        
    }
};
