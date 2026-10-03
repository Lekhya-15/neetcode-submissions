class Solution {
public:
    void backtrack(int target,vector<int>& nums,int sum,vector<vector<int>>& ans,vector<int> path,int i){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        
        if(i<nums.size() && nums[i]+sum<=target){
            path.push_back(nums[i]);
            backtrack(target,nums,sum+nums[i],ans,path,i);
            path.pop_back();
        }

        for(int j=i+1;j<nums.size();j++){
        if(nums[j]+sum<=target){
            path.push_back(nums[j]);
            backtrack(target,nums,sum+nums[j],ans,path,j);
            path.pop_back();
        }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        backtrack(target,nums,0,ans,path,0);
        return ans;
    }
};
