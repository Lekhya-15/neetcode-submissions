class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int j=0;
        int n=gas.size();
        int s1=0;int s2=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            s1+=gas[i];s2+=cost[i];
            if(total<0){
                total=0;
                j=i+1;
            }
        }

        if(s1<s2) return -1;
        return j;

    }
};
