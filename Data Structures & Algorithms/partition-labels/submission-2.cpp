class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int> map,map2;
        for(char c:s){
            map[c]++;
            map2[c]=1;
        }

        vector<int> res;
        int x=0;
        queue<int> q;
        int i=0;
        for(char c:s){
            if(x && q.empty()) res.push_back(x);
            if(q.empty()) x=0;
            if(map2[c]){
                q.push(c);
                x+=map[c];
                map2[c]--;
            }
            map[c]--;
            while(!q.empty() && map[q.front()]==0) q.pop();
            i++;
        }
        res.push_back(x);
        return res;
        
    }
};
