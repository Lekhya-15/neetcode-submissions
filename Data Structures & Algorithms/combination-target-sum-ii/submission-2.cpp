class Solution {
public:
    void backtrack(int target,vector<int> path,vector<vector<int>>& ans,vector<int>& nums,int i){
        if(target==0){
            ans.push_back(path);
            return;
        }
        if(i>=nums.size()) return;

        if(target>=nums[i]){
            path.push_back(nums[i]);
            backtrack(target-nums[i],path,ans,nums,i+1);
            path.pop_back();
        }

        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        backtrack(target,path,ans,nums,i+1);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        backtrack(target,path,ans,candidates,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
