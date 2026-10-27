class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);

        for(int i=0;i<prereq.size();i++){
            adj[prereq[i][1]].push_back(prereq[i][0]);
            indeg[prereq[i][0]]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indeg[i]!=0) return false;
        }
        return true;
    }
};
