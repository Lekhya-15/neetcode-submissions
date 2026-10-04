class Solution {
public:
    void backtrack(int i,vector<int>& path,vector<vector<int>>& ans,vector<int>& nums){
        if(i==nums.size()){
            ans.push_back(path);
            return;
        }

        path.push_back(nums[i]);
        backtrack(i+1,path,ans,nums);
        path.pop_back();

        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }

        backtrack(i+1,path,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(0,path,ans,nums);
        return ans;
    }
};
