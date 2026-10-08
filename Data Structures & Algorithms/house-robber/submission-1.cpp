class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        vector<vector<int>> dp(nums.size(),vector<int>(2,0));

        dp[0][1]=nums[0];
        dp[1][1]=nums[1];
        dp[1][0]=max(dp[0][1],dp[0][0]);

        for(int i=2;i<nums.size();i++){
            dp[i][1]=nums[i]+max(dp[i-2][0],dp[i-2][1]);
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        }

        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};
