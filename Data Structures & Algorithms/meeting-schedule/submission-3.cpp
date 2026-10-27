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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval& a,Interval& b){
            if(a.end!=b.end) return a.end<b.end;
            return a.start<b.start;
        });

        int ans=0;
        int y=-1;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i].start>=y){
                ans++;
                y=intervals[i].end;
            }
        }
        return intervals.size()-ans == 0;
    }
};
