class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            if(a[1]!=b[1]) return a[1]<b[1];
            return a[0]<b[0];
        });

        int ans=1;
        int y=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=y){
                ans++;
                y=intervals[i][1];
            }
        }
        return intervals.size()-ans;

    }
};