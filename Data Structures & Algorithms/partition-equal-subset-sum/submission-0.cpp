class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2) return false;
        sum=sum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }

        for(int t=0;t<=sum;t++) if(t==nums[0]) dp[0][t]=1;

        for(int i=1;i<n;i++){
            for(int t=0;t<=sum;t++){
            if(nums[i]>t) dp[i][t] = dp[i-1][t]; 
            else dp[i][t]=(dp[i-1][t] || dp[i-1][t-nums[i]]);
            }
        }

        return dp[n-1][sum];
        
    }
};
