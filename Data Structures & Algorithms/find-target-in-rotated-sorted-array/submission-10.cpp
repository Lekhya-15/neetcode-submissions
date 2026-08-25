class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();

        int l=0;int r=n-1;

        while(l<r){
            
            int mid=l+(r-l)/2;
            
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }

        }

        int pivot=l;
        if(nums[0]>target || pivot==0){
            l=pivot;r=n-1;
        }
        else{
            l=0;r=pivot-1;
        }

        while(l<=r){
            
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        
        return -1;
    }
};
