class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;int r=m*n-1;

        while(l<=r){
            int i=l/n;int j=l%n;
            int k=r/n;int p=r%n;

            if(matrix[i][j]==target) return true;
            if(matrix[k][p]==target) return true;

            int mid=l+(r-l)/2;
            if(matrix[mid/n][mid%n]==target) return true;
            else if(matrix[mid/n][mid%n]<target) l=mid+1;
            else r=mid-1;
        }

        return false;

        
    }
};
