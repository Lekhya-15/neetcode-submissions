class Solution {
public:
    // int rec(int i,int s,vector<int> prices,vector<vector<int>>& dp){
    //     if(i>=prices.size() && s==0) return 0;
    //     if(i>=prices.size()) return INT_MIN;

    //     if(dp[i][s]!=INT_MIN) return dp[i][s];
    //     int skip= rec(i+1,s,prices,dp);
    //     int take=INT_MIN;
    //     if(s==0){
    //         int val = rec(i+1,1,prices,dp);
    //         if(val!=INT_MIN) take=-prices[i]+val;
    //     }
    //     else{
    //         take=prices[i]+rec(i+2,0,prices,dp);
    //     }
    //     return max(skip,take);
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        // return rec(0,0,prices,dp);

        dp[0][0]=0;
        dp[0][1]=INT_MIN;
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0];
            if(dp[i-1][1]!=INT_MIN) dp[i][0]=max(dp[i][0],dp[i-1][1]+prices[i-1]);
            dp[i][1]=dp[i-1][1];
            if(i==1) dp[i][1]=max(dp[i][1],-prices[i-1]);
            if(i-2>=0) dp[i][1]= max(dp[i][1],dp[i-2][0]-prices[i-1]);
        }

        return dp[n][0];
    }
};
