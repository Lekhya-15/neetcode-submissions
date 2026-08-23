class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=0;
        int b=0;
        int m=100000;
        
        for(int i=2;i<=cost.size();i++){
            m=min(a+cost[i-2],b+cost[i-1]);
            a=b;
            b=m;
        }

        return m;
    }
};
