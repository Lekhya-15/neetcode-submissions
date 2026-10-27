/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval& a,Interval& b){
            if(a.start!=b.start) return a.start<b.start;
            return a.end<b.end;
        });

        int ans=0;
        
        // unordered_map<int,int> map;
        // while(1){
        // int y=-1;
        // for(int i=0;i<intervals.size();i++){
        //     if(intervals[i].start>=y && !map.count(i)){
        //         map[i]=1;
        //         y=intervals[i].end;
        //     }
        // }
        // if(y==-1) break;
        // ans++;
        // }
        // return ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& it : intervals) {
            if (!pq.empty() && pq.top() <= it.start) pq.pop();
            pq.push(it.end);
        }
        return pq.size();
    }
};
