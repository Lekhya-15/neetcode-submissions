class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        for(char c:tasks){
            map[c]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto i:map){
            pq.push({i.second,i.first});
        }

        queue<pair<int,char>> q;

        int time=0;

        while(!pq.empty() || !q.empty()){
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    pair<int,char> j = pq.top();
                    if(j.first-1) q.push({j.first-1,j.second});
                    pq.pop();
                    time++;
                }
                else{
                    if(!q.empty()) time++;
                    else break;
                }
            }

            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }

        return time;
    }
};
