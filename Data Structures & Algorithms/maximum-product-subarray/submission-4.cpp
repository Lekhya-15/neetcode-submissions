class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        int mul1=1;
        int mul2=1;
        int m=nums[0];
        
        for(int i=0;i<n;i++){
            int t=mul1*nums[i];
            mul1=max({t,nums[i],mul2*nums[i]});
            mul2=min({t,nums[i],mul2*nums[i]});
            m=max({m,mul1,mul2});
        }
        return m;
    }
};
