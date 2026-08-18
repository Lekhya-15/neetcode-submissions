class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();

        int m=prices[0];
        int p=0;

        for(int i=1;i<n;i++){
            p=max(p,prices[i]-m);
            m=min(m,prices[i]);
        }

        return p;
    }
};
