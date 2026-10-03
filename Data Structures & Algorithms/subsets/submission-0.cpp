class Solution {
public:
    void backtrack(int i,vector<int> path,vector<vector<int>>& ans,vector<int> nums){
        if(i==nums.size()-1){
            ans.push_back(path);
            return;
        }

        path.push_back(nums[i+1]);
        backtrack(i+1,path,ans,nums);
        path.pop_back();

        backtrack(i+1,path,ans,nums);

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(-1,path,ans,nums);
        return ans;
    }
};
