class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<int> parent(n,-1);
        vector<int> visited(n,0);
        int ans=0;
        pq.push({0,0,-1});
        while(!pq.empty()){
            auto [x,y,z]=pq.top();
            pq.pop();
            if(visited[y]) continue;
            ans+=x;
            visited[y]=1;
            parent[y]=z;

            for(int i=0;i<n;i++){
                if(!visited[i]){
                    pq.push({abs(points[i][1]-points[y][1])+abs(points[i][0]-points[y][0]),i,y});
                }
            }
        }
        return ans;
    }
};
