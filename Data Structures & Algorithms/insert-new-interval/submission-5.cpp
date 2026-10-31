class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int add=0;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
                continue;
            }
            if(intervals[i][1]>=newInterval[0] && !add){
            int start = min(newInterval[0],intervals[i][0]);
            int end = newInterval[1];
            while(i<n && end>=intervals[i][0]){
                end=max(end,intervals[i][1]);
                i++;
            }
            ans.push_back({start,end});
            add=1;
            }
            if(i<n) ans.push_back(intervals[i]);
        }
        if(n==0) ans.push_back(newInterval);
        if(intervals==ans && newInterval[0]>intervals[n-1][1]){
            ans.push_back(newInterval);
        }
        
        return ans;
    }
};
