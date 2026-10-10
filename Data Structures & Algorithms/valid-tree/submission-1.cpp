class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a]);
    }

    void unions(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;

        if(rank[a]>rank[b]) parent[b]=a;
        else if(rank[b]>rank[a]) parent[a]=b;
        else{
            parent[a]=b;
            rank[b]++;
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(find(u)==find(v)) return false;
            unions(u,v);
        }

        int root=find(0);
        for(int i=1;i<n;i++){
            if(root!=find(i)) return false;
        }

        return true;
    }
};
