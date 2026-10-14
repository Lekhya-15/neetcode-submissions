class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> sum;
        sum[0] = 1;

        for (int num : nums) {
            unordered_map<int, int> next;

            for (auto [x, ways] : sum) {
                next[x + num] += ways;
                next[x - num] += ways;
            }

            sum = move(next);
        }

        return sum[target];
    }
};
