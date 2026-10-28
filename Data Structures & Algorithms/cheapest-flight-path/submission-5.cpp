class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flight.size();i++){
            adj[flight[i][0]].push_back({flight[i][1],flight[i][2]});
        }

        // vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX));
        // for(int i=0;i<=k;i++){
        //     dist[src][i]=0;
        // }
        // priority_queue<vector<int> , vector<vector<int>>, greater<vector<int>>> pq;
        // pq.push({0,src,-1});

        // while(!pq.empty()){
        //     auto vec=pq.top();
        //     pq.pop();
        //     if(vec[2]>=0 && vec[0]>dist[vec[1]][vec[2]]) continue;

        //     for(auto [m,d]:adj[vec[1]]){
        //         if(vec[2]<k){
        //             if(dist[m][vec[2]+1]>vec[0]+d){
        //                 dist[m][vec[2]+1]=vec[0]+d;
        //                 pq.push({dist[m][vec[2]+1],m,vec[2]+1});
        //             }
        //         }
        //     }
        // }
        // int m=INT_MAX;
        // for(int i=0;i<=k;i++){
        //     m=min(m,dist[dst][i]);
        // }
        // if(m!=INT_MAX) return m;
        // return -1;

        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        queue<vector<int>> q;
        q.push({0,src,-1});
        while(!q.empty()){
            auto vec=q.front();
            q.pop();

            for(auto [m,d]:adj[vec[1]]){
                if(vec[2]<k){
                    if(dist[m]>vec[0]+d){
                        dist[m]=vec[0]+d;
                        q.push({dist[m],m,vec[2]+1});
                    }
                }
            }
        }

        if(dist[dst]!=INT_MAX) return dist[dst];
        else return -1;

    }
};
