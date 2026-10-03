class Solution {
public:
    void backtrack(vector<int>& path,vector<vector<int>>& ans,unordered_map<int,int>& map,vector<int>& nums){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!map[nums[i]]){
                path.push_back(nums[i]);map[nums[i]]=1;
                backtrack(path,ans,map,nums);
                path.pop_back();map[nums[i]]=0;
            }
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_map<int,int> map;
        backtrack(path,ans,map,nums);
        return ans;
    }
};
