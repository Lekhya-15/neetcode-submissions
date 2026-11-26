class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int mul=1;
        uint32_t ans=0;

        for(int i=31;i>=0;i--){
            ans+=mul*(n>>i & 1);
            mul*=2;
        }

        return ans;
    }
};
