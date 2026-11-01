class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = *max_element(piles.begin(),piles.end());

        int l=1; int r=m;
        while(l<r){
            int mid=l+(r-l)/2;
            long sum=0;
            for(int p:piles) sum+=(ceil((double)p/mid));
            if(sum<=h) r=mid;
            else l=mid+1;
        }

        return l;
    }
};
