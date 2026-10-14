class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //sum of subset=(target+totalsum)/2
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if (abs(target) > sum) return 0;

        if((sum+target)%2) return 0;
        sum=(sum+target)/2;

        vector<int> dp(sum+1,0);
        dp[0]=1;

        for(int num:nums){
            for( int t=sum;t>=num;t--){
                dp[t]+=dp[t-num];
            }
        }

        return dp[sum];
        // unordered_map<int,int> sum;
        // sum[0] = 1;

        // for (int num : nums) {
        //     unordered_map<int, int> next;

        //     for (auto [x, ways] : sum) {
        //         next[x + num] += ways;
        //         next[x - num] += ways;
        //     }

        //     sum = move(next);
        // }

        // return sum[target];
    }
};
