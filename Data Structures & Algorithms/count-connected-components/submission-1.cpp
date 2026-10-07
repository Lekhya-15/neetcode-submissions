class Solution {
public:
    void dfs(int i,vector<vector<int>> adj,vector<int>& visited){
        visited[i]=1;
        for(auto j:adj[i]){
            if(!visited[j]) dfs(j,adj,visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        int comp=0;
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                comp++;
            }
        }

        return comp;
    }
};
