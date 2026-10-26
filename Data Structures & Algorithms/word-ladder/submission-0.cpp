class Solution {
public:
    bool isadj(string s1,string s2){
        int diff=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) diff++;
        }
        return diff==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        vector<vector<int>> adj(n+1);
        int source=-1;

        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord) continue;
            if(wordList[i]==endWord) source=i;
            if(isadj(beginWord,wordList[i])){
                adj[i].push_back(n);
                adj[n].push_back(i);
            }
            for(int j=i+1;j<n;j++){
                if(wordList[j]==beginWord) continue;
                if(isadj(wordList[i],wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if(!adj[n].size()) return 0;
        if(source==-1) return 0;
        
        queue<int> q;
        int ans=0;
        q.push(source);
        vector<int> visited(n+1,0);
        visited[source]=1;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto v:adj[u]){
                if(!visited[v]){
                    visited[v]=visited[u]+1;
                    q.push(v);
                }
            }
        }
        return visited[n];
    }
};