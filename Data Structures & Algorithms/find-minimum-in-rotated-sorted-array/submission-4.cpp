class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size();

        int l=0;int r=n-1;

        while(l<=r){
            if(l==r) return nums[l];
            if(l+1==r) return min(nums[l],nums[r]);
            int mid=l+(r-l)/2;

            if(nums[mid-1]>nums[mid] && nums[mid+1]>nums[mid]) return nums[mid];
            else if(nums[mid]>nums[mid+1]) return nums[mid+1];
            else if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else if(nums[mid]<nums[r]){
                r=mid-1;
            }

        }

        return -1;

    }
};
