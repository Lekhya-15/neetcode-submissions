class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1,INT_MAX);
        time[k]=0;
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [x,y]=pq.top();
            pq.pop();

            for(auto [r,d]:adj[y]){
                if(x+d<time[r]){
                    time[r]=x+d;
                    pq.push({time[r],r});
                }
            }
        }
        int m=INT_MIN;
        for(int i=1;i<=n;i++) m=max(m,time[i]);
        if(m==INT_MAX) return -1;
        return m;
    }
};
